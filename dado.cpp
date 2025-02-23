#include "dado.h"

// Constructor por defecto
Dado::Dado() {
    numero = 1; // Valor por defecto
}

// Constructor con parámetros
Dado::Dado(int numero) {
    this->numero = numero;
}

// Getter para obtener el número
int Dado::getNumero() const {
    return numero;
}

// Setter para modificar el número
void Dado::setNumero(int numero) {
    this->numero = numero;
}
