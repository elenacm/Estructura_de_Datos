#include "Diccionario.h"
#include "Sopa_Letras.h"
#include <fstream>
#include <iostream>
#include <string>
using namespace std;


ostream & operator<<(ostream & os, const pair<string,string> & p){
  os << p.first << " ; " << p.second << endl;
  return os;
}

void ImprimirDiccionario(Diccionario &D){
  Diccionario::iterator it;
  for (it=D.begin(); it!=D.end();++it){
    cout << *it << endl;
  }
}

void imprimeDefiniciones(Diccionario &D){
  Diccionario::iterator it = D.begin();

  for (it=D.begin(); it!=D.end();++it){
    cout << "Definicion-> " << (*it).second << endl << endl;
  }
}

int main(int argc, char * argv[]){
  if (argc!=2){
      cout << "Dime el nombre del fichero con el diccionario" << endl;
      return 0;
   }

   ifstream f (argv[1]);
   if (!f){
    cout<<"No puedo abrir el fichero " << argv[1] << endl;
    return 0;
   }

   Diccionario T;
   f >> T; //Cargamos en memoria el diccionario
   cout << T << "EL DICCIONARIO TIENE " << T.getMultimap().size() << " ELEMENTOS" << endl;
   string a;


   Diccionario Dtema;
   do{
     cout << endl << "************Dime un tema: ";
     getline(cin,a);
     cout << endl << "************Palabras con ese tema: " << endl;
     Dtema = T.ObtainPalabrasconDeficionContiene(a);

     cout << Dtema;
     cout << "EL DICCIONARIO TIENE " << Dtema.getMultimap().size() << " ELEMENTOS" << endl;
   }while(Dtema.getMultimap().size()==0);
//   ImprimirDiccionario(Dtema);

   cout << endl << "************Dime cuantas palabras quieres que tenga la sopa: ";
   int b;
   cin >> b;

   Diccionario nuevo = Dtema.escogePalabras(b);           // escoge al azar b palabras con sus definiciones

   nuevo.ponePalabraEnSopa();    // pone todas las palabras de forma aleatoria en una sopa de letras
   Sopa_Letras Sl = nuevo.getSopa();

   while (Sl.Numero_Palabras()!=0){
      cout << endl;
      imprimeDefiniciones(nuevo);
      cout << Sl << endl;

      cout <<"Dime una palabra (en minuscula): ";
      string word;
      cin >> word;

      cout <<"Dime la fila: ";
      int row;
      cin>>row;
      cout<<"Dime la columna: ";
      int col;
      cin>>col;

      cout<<"Direccion Arriba (vu), Abajo (vd), Izquierda (hi) , Derecha (hd), Diagonal abajo derecha (dd),Diagonal abajo izquierda (di) : ";
      string direccion;
      cin>>direccion;

      if (!Sl.Esta_Palabra(word,row,col,direccion)){//Esta?
         cout<<"LA PALABRA "<< word << " NO ESTÁ"<<endl;
      }
      else{
          //La pone en negrita. Ademas la pone dentro de la lista de palabras descubiertas.
          cout  << endl << "LA PALABRA " << word << " ES CORRECTA."  << endl;
          Sl.Poner_Acertada(word, row, col, direccion);
          nuevo.Borrar(word);
      }
   }
   cout << endl << Sl << endl;
   cout << "¡SOPA DE LETRAS CONSEGUIDA!" << endl;
}
