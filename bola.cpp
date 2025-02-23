#include "bola.h"

// Constructor por defecto
Bola::Bola() {
    color = "Blanco";  // Valor por defecto
    estado = "afuera"; // Estado inicial
}

// Constructor con parámetros
Bola::Bola(string color, string estado) {
    this->color = color;
    this->estado = estado;
}

// Getter para el color
string Bola::getColor() const {
    return color;
}

// Setter para modificar el color
void Bola::setColor(string color) {
    this->color = color;
}

// Getter para el estado
string Bola::getEstado() const {
    return estado;
}

// Setter para modificar el estado
void Bola::setEstado(string estado) {
    this->estado = estado;
}
