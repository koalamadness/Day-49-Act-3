#ifndef LISTA_H
#define LISTA_H

#include <iostream>

#include "listexception.h"
#include "cancion.h"

class Lista 
{
private:
  Cancion listaExitos[3000];
  int ultimo;

  bool posValida(const int&);

  void copiarTodo(const Lista&);

  void intercambiar(Cancion&, Cancion&);

public:
  Lista();
  Lista(const Lista&);

  bool estaVacio();
  bool estaLleno();

  void insertar(const Cancion&, const int&);

  void eliminar(const int&);

  int getPrimPos();
  int getUltPos();
  int getAntPos(const int&);
  int getSigPos(const int&);

  Cancion recuperar(const int&);

  std::string toString();

  void eliminarTodo();

  int encontrarCancionLinear(const Cancion&);
  int encontrarCancionLinearInter(const Cancion&);
  int encontrarCancionBinary(const Cancion&);
  int encontrarCancionBinaryInter(const Cancion&);

  // Lo siento, sé que es de mal gusto repetir tanto código
  // Me atrasé en otra materia :c 
  void sortBubbleNombre();
  void sortBubbleInter();
  void sortInsertNombre();
  void sortInsertInter();
  void sortSelectNombre();
  void sortSelectInter();
  void sortShellNombre();
  void sortShellInter();

  Lista& operator = (const Lista&);

};

#endif