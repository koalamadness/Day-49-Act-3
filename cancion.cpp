#include "cancion.h"

using namespace std;

Cancion::Cancion() {}

Cancion::Cancion(const Cancion& c) : nombre(c.nombre), autor(c.autor), interprete(c.interprete), posRanking(c.posRanking) { }

Cancion& Cancion::operator=(const Cancion & c)
{
  nombre = c.nombre;
  autor = c.autor;
  interprete = c.interprete;
  posRanking = c.posRanking;

  return *this;
}

string Cancion::getArhivoMP3()  
{
  archivoMP3 = to_string(nombre[0]) + to_string(autor[0]) + nombre.back() + autor.back() + ".mp3";

  return archivoMP3;
}


string Cancion::getNombre() const {return nombre;}
string Cancion::getAutor() const {return autor;}
string Cancion::getInterprete() const {return interprete;}
unsigned int Cancion::getPosRanking() const {return posRanking;}

string Cancion::toString() const
{
  string cadena;
  cadena += nombre + " | ";
  cadena += autor + " | ";
  cadena += interprete + " | ";
  cadena += to_string(posRanking) + " | ";
  return cadena;
}
void Cancion::setArchivoMP3(const string& a) {archivoMP3 = a;}
void Cancion::setNombre(const string& n) {nombre = n;}
void Cancion::setAutor(const string& a) {autor = a;}
void Cancion::setInterprete(const string& i) {interprete = i;}
void Cancion::setPosRanking(const unsigned int& p) {posRanking = p;}

bool Cancion::operator == (const Cancion& c) const
{
  return nombre == c.nombre;
}

bool Cancion::operator != (const Cancion& c) const
{
  return nombre != c.nombre;
}

bool Cancion::operator < (const Cancion& c) const
{
  return nombre < c.nombre;
}

bool Cancion::operator <= (const Cancion& c) const
{
  return nombre <= c.nombre;
}

bool Cancion::operator > (const Cancion& c) const
{
  return nombre > c.nombre;
}

bool Cancion::operator >= (const Cancion& c) const
{
  return nombre >= c.nombre;
}