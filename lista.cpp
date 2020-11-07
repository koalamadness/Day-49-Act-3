#include "lista.h"

using namespace std;

// Privado

void Lista::copiarTodo(const Lista& l) 
{
  int i(0);
  while(i <= l.ultimo)
  {
    listaExitos[i] = l.listaExitos[i];
    i++;
  }
  ultimo = l.ultimo;
}

bool Lista::posValida(const int& p) 
{
  return p >= 0 and p <= ultimo;
}

void Lista::intercambiar(Cancion& a, Cancion& b)
{
  Cancion aux(a);
  a = b;
  b = aux;
}

// Público

Lista::Lista() : ultimo(-1) { }
Lista::Lista(const Lista& l) 
{
  copiarTodo(l);
} 

bool Lista::estaVacio() {return ultimo == -1;} 
bool Lista::estaLleno() {return ultimo == 2999;} 

void Lista::insertar(const Cancion& c, const int& p)
{
  if(estaLleno())
  {
    throw ListException("Desbordamiento de datos , insertar");
  }

  if(p != -1 and !posValida(p))
  {
    throw ListException("Posición invalida, insertar");
  }

  int i(ultimo);
  while(i > p)
  {
    listaExitos[i + 1] = listaExitos[i];
    i--;
  }

  listaExitos[p + 1] = c;

  ultimo++;
}

void Lista::eliminar(const int& p)
{
  int i = p;

  if(!posValida(p))
  {
    throw ListException("Posición invalida, eliminar");
  }

  while(i < ultimo)
  {
    listaExitos[i] = listaExitos[i + 1];
    i++;
  }

  ultimo--;  
}

int Lista::getPrimPos()
{
  if(estaVacio()) 
  {
    return -1;
  }
  return 0;
}
int Lista::getUltPos() {return ultimo;}

int Lista::getAntPos(const int& p) 
{
  if(p == getPrimPos() || !posValida(p))
  {
    return -1;
  }
  return p - 1;
}

int Lista::getSigPos(const int& p)
{
  if(p == getUltPos() || !posValida(p))
  {
    return -1;
  }

  return p + 1;
}

Cancion Lista::recuperar(const int& p) {
  if(!posValida(p)) {
    throw ListException("Posición invalida, recuperar");
  }

  return listaExitos[p];
}

string Lista::toString()
{
  string cadena = "";
  int i = 0;
  while(i <= ultimo)
  {
    cadena += to_string(i) + " | ";
    cadena += listaExitos[i].toString();
    cadena += "\n";    
    i++;
  }
  return cadena;
}

void Lista::eliminarTodo() {ultimo = -1;}

int Lista::encontrarCancionLinear(const Cancion& c)
{
  int i(0);

  while(i <= ultimo)
  {
    
    if(listaExitos[i].getNombre() == c.getNombre()) 
    {
      return i;
    }
    
    i++;
  }
  return -1;
}

int Lista::encontrarCancionLinearInter(const Cancion& c)
{
  int i(0);

  while(i <= ultimo)
  {
    
    if(listaExitos[i].getInterprete() == c.getInterprete()) 
    {
      return i;
    }
    
    i++;
  }
  return -1;
}

int Lista::encontrarCancionBinary(const Cancion& c)
{
 int i(0), j(ultimo), m;

 while(i <= j)
 {
   m = (i + j)/2;
 
  if(listaExitos[m].getNombre() == c.getNombre()) 
  {
    return m;
  }

  if(c.getNombre() < listaExitos[m].getNombre()) 
  {
    j = m - 1;
  }
  else
  {
    i = m + 1;
  }
 }

 return -1;

}

int Lista::encontrarCancionBinaryInter(const Cancion& c)
{
 int i(0), j(ultimo), m;

 while(i <= j)
 {
   m = (i + j)/2;
 
  if(listaExitos[m].getInterprete() == c.getInterprete()) 
  {
    return m;
  }

  if(c.getInterprete() < listaExitos[m].getInterprete()) 
  {
    j = m - 1;
  }
  else
  {
    i = m + 1;
  }
 }

 return -1;

}

void Lista::sortBubbleNombre()
{
  int i(ultimo), j;
  bool bandera;

  do 
  {
    bandera = false;
    int j = 0;

    while(j < i)
    {
      if (listaExitos[j].getNombre() > listaExitos[j + 1].getNombre())
      {
        intercambiar(listaExitos[j], listaExitos[j + 1]);
        
        bandera = true;
      }

      j++;
    }

    i--;
  } while(bandera);
}

void Lista::sortBubbleInter()
{
  int i(ultimo), j;
  bool bandera;

  do 
  {
    bandera = false;
    int j = 0;

    while(j < i)
    {
      if (listaExitos[j].getInterprete() > listaExitos[j + 1].getInterprete())
      {
        intercambiar(listaExitos[j], listaExitos[j + 1]);
        
        bandera = true;
      }

      j++;
    }

    i--;
  } while(bandera);
}


void Lista::sortInsertNombre()
{
  int i(1), j;
  Cancion aux;

  while(i <= ultimo) 
  {
    aux = listaExitos[i];
    j = i;

    while(j > 0 and aux.getNombre() < listaExitos[j - 1].getNombre())
    {
      listaExitos[j] = listaExitos[j - 1];

      j--;
    }

    if(i != j)
    {
      listaExitos[j] = aux;
    }

    i++;
  }
}

void Lista::sortInsertInter()
{
  int i(1), j;
  Cancion aux;

  while(i <= ultimo) 
  {
    aux = listaExitos[i];
    j = i;

    while(j > 0 and aux.getInterprete() < listaExitos[j - 1].getInterprete())
    {
      listaExitos[j] = listaExitos[j - 1];

      j--;
    }

    if(i != j)
    {
      listaExitos[j] = aux;
    }

    i++;
  }
}

void Lista::sortSelectNombre()
{
  int i(0), j, m;

  while(i < ultimo) 
  {
    m = i;
    j = i + 1;

    while(j <= ultimo) 
    {
      if(listaExitos[j].getNombre() < listaExitos[m].getNombre()) 
      {
        m = j;
      }
      j++;
    }

    if(i != m)
    {
      intercambiar(listaExitos[i], listaExitos[m]);
    }

    i++;
  }
}

void Lista::sortSelectInter()
{
  int i(0), j, m;

  while(i < ultimo) 
  {
    m = i;
    j = i + 1;

    while(j <= ultimo) 
    {
      if(listaExitos[j].getInterprete() < listaExitos[m].getInterprete()) 
      {
        m = j;
      }
      j++;
    }

    if(i != m)
    {
      intercambiar(listaExitos[i], listaExitos[m]);
    }

    i++;
  }
}

void Lista::sortShellNombre()
{
  float factor(1.0 / 2.0);
  int dif((ultimo + 1) * factor), i, j;

  while(dif > 0)
  {
    i = dif;

    while(i <= ultimo)
    {
      j = i;

      while(j >= dif and listaExitos[j - dif].getNombre() > listaExitos[j].getNombre())
      {
        intercambiar(listaExitos[j - dif], listaExitos[j]);

        j -= dif;
      }

      i++;
    }

    dif *= factor; 
  }
}

void Lista::sortShellInter()
{
  float factor(1.0 / 2.0);
  int dif((ultimo + 1) * factor), i, j;

  while(dif > 0)
  {
    i = dif;

    while(i <= ultimo)
    {
      j = i;

      while(j >= dif and listaExitos[j - dif].getInterprete() > listaExitos[j].getInterprete())
      {
        intercambiar(listaExitos[j - dif], listaExitos[j]);

        j -= dif;
      }

      i++;
    }

    dif *= factor; 
  }
}

Lista& Lista::operator = (const Lista& l)
{
  copiarTodo(l);
  return *this;
}
