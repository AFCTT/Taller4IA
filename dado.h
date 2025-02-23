#ifndef DADO_H
#define DADO_H

#include <iostream>

using namespace std;

class Dado {
private:
    int numero;

public:
    // Constructor
    Dado();
    Dado(int numero);

    // Getter y Setter
    int getNumero() const;
    void setNumero(int numero);
};

#endif // DADO_H
