#ifndef CANCION_H
#define CANCION_H

#include <iostream>

class Cancion 
{
private:
  std::string archivoMP3;
  std::string nombre;
  std::string autor;
  std::string interprete;
  unsigned int posRanking;

public:
  Cancion();
  Cancion(const Cancion&);
  
  std::string getArhivoMP3(); 
  std::string getNombre() const;
  std::string getAutor() const;
  std::string getInterprete() const;
  unsigned int getPosRanking() const;

  static int compByName(const Cancion&, const Cancion&);

  std::string toString() const; 

  void setArchivoMP3(const std::string&); 
  void setNombre(const std::string&);
  void setAutor(const std::string&);
  void setInterprete(const std::string&);
  void setPosRanking(const unsigned int&); 

  bool operator == (const Cancion&) const;
  bool operator != (const Cancion&) const;
  bool operator < (const Cancion&) const;
  bool operator <= (const Cancion&) const;
  bool operator > (const Cancion&) const;
  bool operator >= (const Cancion&) const;

  Cancion& operator = (const Cancion&);
};

#endif