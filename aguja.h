#ifndef AGUJA_H
#define AGUJA_H

#include <iostream>
#include <list>
#include "bola.h"

using namespace std;

class Aguja {
private:
    int id;
    list<Bola> bolas;

public:
    // Constructores
    Aguja();
    Aguja(int id, list<Bola> bolas);

    // Getters y Setters
    int getId() const;
    void setId(int id);

    list<Bola> getBolas() const;
    void setBolas(list<Bola> bolas);

    // Método para agregar una bola a la lista
    void agregarBola(Bola bola);
};

#endif // AGUJA_H
