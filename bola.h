#ifndef BOLA_H
#define BOLA_H

#include <iostream>
#include <string>

using namespace std;

class Bola {
private:
    string color;
    string estado; // "en la carcel", "afuera" o "en el tablero"

public:
    // Constructores
    Bola();
    Bola(string color, string estado);

    // Getters y Setters
    string getColor() const;
    void setColor(string color);
    
    string getEstado() const;
    void setEstado(string estado);
};

#endif // BOLA_H
