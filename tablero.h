#define TABLERO_H
#include <iostream>
#include <string>
#include <list>
#include "aguja.h"
#include "dado.h"

using namespace std;

class Tablero{
private:
  string nombre;
  list<Aguja> agujas;
  Dado dado;

public:
  string obtenernombre();
  void Setnombre(string nombre);
  list<Aguja> Obteneragujas();
  void Setagujas(Aguja aguja);
  int Obtenerdado();
  void Setdado(Dado dado);

    
};
