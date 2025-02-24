#include <iostream>
#include <stack>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <limits>
using namespace std;

class Dado {
public:
    int lanzar() { return rand() % 6 + 1; }
};

class Bola {
public:
    int jugadorId;
    Bola(int jugador) : jugadorId(jugador) {}
};

class Aguja {
public:
    stack<Bola> bolas;
    void agregarBolas(int cantidad, int jugador) { 
        for (int i = 0; i < cantidad; ++i) {
            bolas.push(Bola(jugador)); 
        }
    }
    void removerBola() { if (!bolas.empty()) bolas.pop(); }
    bool estaVacia() { return bolas.empty(); }
    int obtenerJugador() { return bolas.empty() ? -1 : bolas.top().jugadorId; }
    bool tieneUnaFicha() { return bolas.size() == 1; }
};

class Tablero {
private:
    vector<Aguja> agujas;
    stack<Bola> carcel[2];
    vector<Bola> zonaDeSalida[2];
    Dado dado;
    int turno;
public:
    Tablero() : agujas(24), turno(0) {}
    void inicializar();
    void mostrar();
    void jugarTurno();
    bool moverFicha(int origen, int destino, int dadoValor);
    bool verificarGanador();
    int evaluarEstado();
    int minMax(int profundidad, bool maximizando, int dadoValor);
    pair<int, int> mejorMovimiento(int dadoValor);
};

void Tablero::inicializar() {
    agujas[0].agregarBolas(2, 0);
    agujas[11].agregarBolas(5, 0);
    agujas[16].agregarBolas(3, 0);
    agujas[18].agregarBolas(5, 0);
    
    agujas[5].agregarBolas(5, 1);
    agujas[7].agregarBolas(3, 1);
    agujas[12].agregarBolas(5, 1);
    agujas[23].agregarBolas(2, 1);
}

void Tablero::mostrar() {
    for (int i = 0; i < 24; i++) {
        cout << "[" << i+1 << ": " ;
        if (agujas[i].obtenerJugador() == 0) cout << agujas[i].bolas.size() << " Negras";
        else if (agujas[i].obtenerJugador() == 1) cout << agujas[i].bolas.size() << " Blancas";
        else cout << "No fichas";
        cout<<"] ";
        
        if (i % 6 == 5) cout << endl;
    }
    cout << "Carcel Negras: " << carcel[0].size() << " | Carcel Blancas: " << carcel[1].size() << endl;
}

bool Tablero::moverFicha(int origen, int destino, int dadoValor) {
    if (origen < 0 || origen >= 24 || destino < 0 || destino >= 24) return false;
    if (destino - origen != dadoValor && origen - destino != dadoValor) return false;
    if (agujas[origen].estaVacia() || agujas[origen].obtenerJugador() != turno) return false;
    if (!agujas[destino].estaVacia() && agujas[destino].obtenerJugador() != turno && !agujas[destino].tieneUnaFicha()) return false;
    if (!agujas[destino].estaVacia() && agujas[destino].tieneUnaFicha() && agujas[destino].obtenerJugador() != turno) {
        carcel[!turno].push(agujas[destino].bolas.top());
        agujas[destino].removerBola();
    }
    agujas[destino].agregarBolas(1, turno);
    agujas[origen].removerBola();
    return true;
}


void Tablero::jugarTurno() {
    int d1 = dado.lanzar();
    cout << "Jugador " << turno << " lanza: " << d1 << endl;

    if (turno == 1) { // Turno de la IA
        pair<int, int> mov = mejorMovimiento(d1);
        if (mov.first != -1 && mov.second != -1 && moverFicha(mov.first, mov.second, d1)) {
            cout << "IA mueve de " << mov.first + 1 << " a " << mov.second + 1 << endl;
        } else {
            cout << "IA no encontró un movimiento válido." << endl;
        }
    } else { // Turno del jugador humano
        int origen, destino;
        do {
            cout << "Ingrese movimiento origen: ";
            cin >> origen;
            cout << "Ingrese el destino: ";
            cin >> destino;
            if (destino - origen != d1 && origen - destino != d1) {
                cout << "¡Movimiento inválido! La diferencia debe coincidir con el dado (" << d1 << ")." << endl;
            }
        } while (destino - origen != d1 && origen - destino != d1);

        if (moverFicha(origen, destino, d1)) {
            cout << "Movimiento realizado." << endl;
        } else {
            cout << "Movimiento inválido." << endl;
        }
    }

    turno = 1 - turno; // Cambia de turno
}

int Tablero::evaluarEstado() {
    cout << "Evaluando estado del tablero..." << endl;
    int score = 0;
    for (int i = 0; i < 24; i++) {
        stack<Bola> temp = agujas[i].bolas;
        while (!temp.empty()) {
            int jugador = temp.top().jugadorId;
            int posicion = (jugador == 1) ? i : (23 - i);
            int valor = (jugador == 1 ? i : -i);
            if (agujas[i].tieneUnaFicha()) {
                valor *= 3;
            }
            int factorCercania = 2 * posicion;
            score += valor + factorCercania;
            temp.pop();
        }
    }
    return score;
}

int Tablero::minMax(int profundidad, bool maximizando, int dadoValor) {
    if (profundidad == 0 || verificarGanador()) cout << "Llamando a evaluarEstado en minMax con profundidad " << profundidad << endl;
    return evaluarEstado();

    int mejorValor = maximizando ? -10000 : 10000;
    int jugadorActual = maximizando ? 1 : 0;
    
    for (int origen = 0; origen < 24; origen++) {
        if (agujas[origen].obtenerJugador() == jugadorActual) {
            int destino = maximizando ? origen - dadoValor : origen + dadoValor;
            if (destino >= 0 && destino < 24 && moverFicha(origen, destino, dadoValor)) {
                cout << "Evaluando movimiento desde " << origen << " hasta " << destino << endl;
                int valor = evaluarEstado() + minMax(profundidad - 1, !maximizando, dadoValor);
                mejorValor = maximizando ? max(mejorValor, valor) : min(mejorValor, valor);
                moverFicha(destino, origen, dadoValor); // Revertimos el movimiento
            }
        }
    }
    return mejorValor;
}

pair<int, int> Tablero::mejorMovimiento(int dadoValor) {
    int mejorValor = numeric_limits<int>::min();
    pair<int, int> mejorMov = {-1, -1};

    for (int origen = 23; origen >= 0; origen--) {
        if (agujas[origen].obtenerJugador() == 1) {
            int destino = origen - dadoValor;
            if (destino >= 0 && moverFicha(origen, destino, dadoValor)) {
                cout << "Probando movimiento IA: " << origen << " -> " << destino << endl;
                int valor = minMax(2, false, dadoValor); // Usamos minMax para evaluar la calidad del movimiento
                if (valor > mejorValor) {
                    mejorValor = valor;
                    mejorMov = {origen, destino};
                }
                moverFicha(destino, origen, dadoValor); // Revertimos el movimiento
            }
        }
    }
    return mejorMov;
}

bool Tablero::verificarGanador() {
    int count0 = 0, count1 = 0;
    for (const auto &aguja : agujas) {
        stack<Bola> temp = aguja.bolas;
        while (!temp.empty()) {
            if (temp.top().jugadorId == 0) count0++;
            else count1++;
            temp.pop();
        }
    }
    if (count0 == 0) {
        cout << "¡Jugador 0 ha ganado!" << endl;
        return true;
    }
    if (count1 == 0) {
        cout << "¡Jugador 1 ha ganado!" << endl;
        return true;
    }
    return false;
}

int main() {
    srand(time(0));
    Tablero juego;
    juego.inicializar();
    while (!juego.verificarGanador()) {
        juego.mostrar();
        juego.jugarTurno();
    }
    cout << "¡Juego terminado!" << endl;
    return 0;
}



