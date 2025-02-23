define BOLA_H
#include <iostream>
#include <string>
#include <list>

using namespace std;

class Bola{
private:
  string color;
  string estado; //en la carcel, afuera o en el tablero.

public:
  string getcolor();
  void setcolor(string color);
  string getestado();
  void setestado(string estado);

}
