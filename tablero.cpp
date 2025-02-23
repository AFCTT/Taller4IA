#include "tablero.h"

// Constructor por defecto
Tablero::Tablero() {
    nombre = "";
}

// Constructor con parámetros
Tablero::Tablero(string nombre, list<Aguja> agujas, Dado dado) {
    this->nombre = nombre;
    this->agujas = agujas;
    this->dado = dado;
}

// Destructor
Tablero::~Tablero() {
    // No hay necesidad de liberar memoria manualmente, 
    // ya que `list` y `string` manejan la memoria automáticamente.
}

// Getter para obtener el nombre
string Tablero::getNombre() const {
    return nombre;
}

// Setter para establecer el nombre
void Tablero::setNombre(string nombre) {
    this->nombre = nombre;
}

// Getter para obtener la lista de agujas
list<Aguja> Tablero::getAgujas() const {
    return agujas;
}

// Setter para establecer una nueva lista de agujas
void Tablero::setAgujas(list<Aguja> agujas) {
    this->agujas = agujas;
}

// Método para agregar una aguja a la lista
void Tablero::agregarAguja(Aguja aguja) {
    agujas.push_back(aguja);
}

// Getter para obtener el valor del dado
int Tablero::getDado() const {
    return dado.getNumero(); 
}

// Setter para establecer el dado
void Tablero::setDado(Dado dado) {
    this->dado = dado;
}
