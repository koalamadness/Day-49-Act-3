#include <iostream>

#include "cancion.h"
#include "lista.h"
#include "menu.h"

using namespace std;

int main() {
  unsigned int op;
  int myPos;
  Menu myMenu;
  Lista myLista;
  Cancion myCancion;
  string myStr;
  unsigned int posRank;

  while(myMenu.getBandera() != false)
  {
    myMenu.printMenu();
    cout << "Posición | Nombre | Autor | Intérprete | Ranking \n";   
    cout << myLista.toString();

    cin >> op;
    myMenu.setOpcion(op);

    switch(myMenu.getOpcion())
    {
      case 1:
      {
        cout << "Nombre: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n' );
        getline(cin, myStr);
        myCancion.setNombre(myStr);
        
        cout << "Autor: ";
        getline(cin, myStr);
        myCancion.setAutor(myStr);

        cout << "Intérprete: ";
        getline(cin, myStr);
        myCancion.setInterprete(myStr);

        cout << "Posición en el ranking: ";
        cin >> posRank;
        myCancion.setPosRanking(posRank);

        cout << "Posición en la que desea insertar la canción en el arreglo: ";
        cin >> myPos;

        try 
        {
          myLista.insertar(myCancion, myPos);
        } 
        catch (ListException ex)
        {
          cout << "Error: " << ex.what() << endl;
        }

        break;
      }

      case 2:
      {
        cout << "Posición en la que desea eliminar la canción en el arreglo: ";
        cin >> myPos;
        
        try 
        {
          myLista.eliminar(myPos);          
        }
        catch (ListException ex)
        {
          cout << "Error: " << ex.what() << endl;
        }

        break;
      }

      case 3:
      {
        cout << "Posición en la que desea recuperar la canción: ";
        cin >> myPos;       

        try 
        {
        cout << myLista.recuperar(myPos).toString() << endl;
        } 
        catch (ListException ex)
        {
          cout << "Error: " << ex.what() << endl;
        }

        break;
      }

      case 4:
      {
        cout << "La primera posición es " << myLista.getPrimPos() << endl;
        cout << myLista.recuperar(myLista.getPrimPos()).toString() << endl;
        break;
      }

      case 5:
      {
        cout << "La última posición es " << myLista.getUltPos() << endl;
        cout << myLista.recuperar(myLista.getUltPos()).toString() << endl;
        break;
      }

      case 6:
      {
        cout << "Ingrese la posición: ";
        cin >> myPos;

        int antPos = myLista.getAntPos(myPos);

        try
        {
        cout << myLista.recuperar(antPos).toString() << endl;

        cout << "La anterior posición es " << myLista.getAntPos(myPos) << endl;        

        }
        catch (ListException ex)
        {
          cout << "Error: " << ex.what() << endl;
        }

        break;
      }

      case 7:
      {
        cout << "Ingrese la posición: ";
        cin >> myPos;

        int sigPos = myLista.getSigPos(myPos);

        try
        {
          cout << myLista.recuperar(sigPos).toString() << endl;

          cout << "La siguiente posición es " << myLista.getSigPos(myPos) << endl;
        }
        catch (ListException ex)
        {
          cout << "Error: " << ex.what() << endl;
        }

        break;
      }                 

      case 8:
      {
        myLista.eliminarTodo();
        break;
      }            

      case 9:
      {
        if(myLista.estaVacio())
        {
          cout << "La lista está vacía \n";
        }
        else
        {
          cout << "La lista no está vacía \n";
        }
  
        break;
      }      

      case 10:
      {
        if(myLista.estaLleno())
        {
          cout << "La lista está llena \n";
        }
        else
        {
          cout << "La lista no está llena \n";
        }
  
        break;
      }                 

      case 11:
      {

        cout << "Nombre de la canción a buscar: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n' );
        getline(cin, myStr);

        myCancion.setNombre(myStr);

        myPos = myLista.encontrarCancionLinear(myCancion);

        cout << "La canción con el nombre " << myStr << " ";

        if(myPos == -1)
        {
          cout << "no se encuentra en la lista" << endl;
        }
        else
        {
          cout << "se encuentra en la posición " << myPos << endl;
          cout << "Canción encontrada: " << endl;
          cout << "Archivo MP3: " << myLista.recuperar(myPos).getArhivoMP3() << endl;
        }     
        break;
      }
      
      case 12: 
      {
        cout << "Nombre de la canción a buscar: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n' );
        getline(cin, myStr);

        myCancion.setNombre(myStr);

        myPos = myLista.encontrarCancionBinary(myCancion);

        cout << "La canción con el nombre " << myStr << " ";

        if(myPos == -1)
        {
          cout << "no se encuentra en la lista" << endl;
        }
        else
        {
          cout << "se encuentra en la posición " << myPos << endl;
          cout << "Canción encontrada: " << endl;
          cout << "Archivo MP3: " << myLista.recuperar(myPos).getArhivoMP3() << endl;
        }   
        break;
      }

      case 13:
      {
        myLista.sortBubbleNombre();
        break;
      }

      case 14:
      {
        myLista.sortBubbleInter();
        break;
      }

      case 15:
      {
        myLista.sortInsertNombre();
        break;
      }

      case 16:
      {
        myLista.sortInsertInter();
        break;
      }

      case 17:
      {
        myLista.sortSelectNombre();
        break;
      }

      case 18:
      {
        myLista.sortSelectInter();
        break;
      }
      
      case 19:
      {
        myLista.sortShellNombre();
        break;
      }

      case 20:
      {
        myLista.sortShellInter();
        break;
      }

      case 21:
      {

        cout << "Intérprete de la canción a buscar: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n' );
        getline(cin, myStr);

        myCancion.setInterprete(myStr);

        myPos = myLista.encontrarCancionLinearInter(myCancion);

        cout << "La canción con el intérprete " << myStr << " ";

        if(myPos == -1)
        {
          cout << "no se encuentra en la lista" << endl;
        }
        else
        {
          cout << "se encuentra en la posición " << myPos << endl;
          cout << "Canción encontrada: " << endl;
          cout << "Archivo MP3: " << myLista.recuperar(myPos).getArhivoMP3() << endl;
        }     
        break;
      }

      case 22:
      {

        cout << "Intérprete de la canción a buscar: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n' );
        getline(cin, myStr);

        myCancion.setInterprete(myStr);

        myPos = myLista.encontrarCancionBinaryInter(myCancion);

        cout << "La canción con el intérprete " << myStr << " ";

        if(myPos == -1)
        {
          cout << "no se encuentra en la lista" << endl;
        }
        else
        {
          cout << "se encuentra en la posición " << myPos << endl;
          cout << "Canción encontrada: " << endl;
          cout << "Archivo MP3: " << myLista.recuperar(myPos).getArhivoMP3() << endl;
        }     
        break;
      }

      case 23:
      {
        myMenu.setBandera(false);
        break;
      }

      default:
      {
        cout << "Opción no disponible \n";
        break;
      }
    }
  }
}