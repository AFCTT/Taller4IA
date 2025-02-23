#include "aguja.h"

// Constructor por defecto
Aguja::Aguja() {
    id = 0; // Valor por defecto
}

// Constructor con parámetros
Aguja::Aguja(int id, list<Bola> bolas) {
    this->id = id;
    this->bolas = bolas;
}

// Getter para obtener el ID
int Aguja::getId() const {
    return id;
}

// Setter para modificar el ID
void Aguja::setId(int id) {
    this->id = id;
}

// Getter para obtener la lista de bolas
list<Bola> Aguja::getBolas() const {
    return bolas;
}

// Setter para modificar la lista de bolas
void Aguja::setBolas(list<Bola> bolas) {
    this->bolas = bolas;
}

// Método para agregar una bola a la lista
void Aguja::agregarBola(Bola bola) {
    bolas.push_back(bola);
}
