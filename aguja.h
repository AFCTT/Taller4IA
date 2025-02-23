define AGUJA_H
#include <iostream>
#include <list>
#include "bola.h"

using namespace std;

class Aguja{
private:
  int id;
  list<Bola> bolas;

public:
  int obtenerid();
  void setid(int id);
  list<Bola> Obtenerbolas();
  void Setbolas(Bola bola);

}
