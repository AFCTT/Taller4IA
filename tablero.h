#ifndef TABLERO_H
#define TABLERO_H

#include <iostream>
#include <string>
#include <list>
#include "aguja.h"
#include "dado.h"

using namespace std;

class Tablero {
private:
    string nombre;
    list<Aguja> agujas;
    Dado dado;

public:
    // Constructor
    Tablero();

    // Constructor con parámetros
    Tablero(string nombre, list<Aguja> agujas, Dado dado);

    // Destructor
    ~Tablero();

    // Métodos de acceso (getters)
    string getNombre() const;
    list<Aguja> getAgujas() const;
    int getDado() const;

    // Métodos de modificación (setters)
    void setNombre(string nombre);
    void setAgujas(list<Aguja> agujas);
    void agregarAguja(Aguja aguja); // Para agregar una aguja a la lista
    void setDado(Dado dado);
};

#endif // TABLERO_H
