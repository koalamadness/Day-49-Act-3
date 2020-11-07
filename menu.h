#ifndef MENU_H
#define MENU_H

#include <iostream>

class Menu 
{
private:
  unsigned opcion;
  bool bandera = true;
public:
  Menu();
  Menu(const Menu&);

  void printMenu();

  unsigned int getOpcion();
  bool getBandera();  

  void setOpcion(unsigned int opc);
  void setBandera(bool b);
};

#endif