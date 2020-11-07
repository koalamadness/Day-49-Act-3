#include "menu.h"

using namespace std;

Menu::Menu() { }
Menu::Menu(const Menu& m) : opcion(m.opcion), bandera(m.bandera) { }

void Menu::printMenu()
{
  cout << "Elija una opción: " << endl;
  cout << "1) Inserta" << endl;
  cout << "2) Elimina" << endl;
  cout << "3) Recupera" << endl;
  cout << "4) Primero" << endl;
  cout << "5) Último" << endl;
  cout << "6) Anterior" << endl;
  cout << "7) Siguiente" << endl;
  cout << "8) Anula" << endl;
  cout << "9) Vacía" << endl;
  cout << "10) Llena" << endl;
  cout << "11) Búsqueda lineal por nombre" << endl;
  cout << "12) Búsqueda binaria por nombre" << endl;
  cout << "13) Ordenamiento Bubble por nombre" << endl;
  cout << "14) Ordenamiento Bubble por intérprete" << endl;
  cout << "15) Ordenamiento Insert por nombre" << endl;
  cout << "16) Ordenamiento Insert por intérprete" << endl;
  cout << "17) Ordenamiento Select por nombre" << endl;
  cout << "18) Ordenamiento Select por intérprete" << endl;
  cout << "19) Ordenamiento Shell por nombre" << endl;
  cout << "20) Ordenamiento Shell por intérprete" << endl;
  cout << "21) Búsqueda lineal por intérprete" << endl;
  cout << "22) Búsqueda binaria por intérprete" << endl;
  cout << "23) Salir" << endl;
}

unsigned int Menu::getOpcion() {return opcion;}
bool Menu::getBandera() {return bandera;}

void Menu::setOpcion(unsigned int opc) {opcion = opc;}
void Menu::setBandera(bool b) {bandera = b;}
