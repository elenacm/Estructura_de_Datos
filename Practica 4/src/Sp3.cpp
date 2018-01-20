#include <iostream>
#include <fstream>
#include "Ontologias.h"
#include "PreguntasED.h"
#include "Sopa_Letras.h"
using namespace std;

void imprimeDefiniciones(PreguntasED &P, set<string>& aux){
  int i = 0;
  pair<set<string>,string> p;
  set<string>::iterator it;
  while (i < P.num_preguntas()){
      p = P.SacaPregunta();
      cout << "Definicion --> " << p.second << endl;
      i++;
      for(it = p.first.begin(); it != p.first.end(); ++it){
        aux.insert(*it);
      }
  }
}

void ponePalabraEnSopa(Sopa_Letras &sopa, set<string> def){
  set<string>::iterator it = def.begin();

  list<string> direcciones;
  direcciones.push_back("vu");
  direcciones.push_back("vd");
  direcciones.push_back("hd");
  direcciones.push_back("hi");
  direcciones.push_back("dd");
  direcciones.push_back("di");

  int fil, col, n_dir;
  list<string>::iterator direccion;
  srand(time(NULL));
  while(it!=def.end()){

    do{
      fil = rand()%10;
      col = rand()%10;
      n_dir = rand()%6; //Elijo una de las 6 opciones que van desde 0 a 5

      int cont = 0;
      for(direccion=direcciones.begin(); cont<n_dir; direccion++)
      cont++;
    }while(!sopa.Esta_Palabra((*it), fil, col-1, *direccion));

    sopa.addPalabra((*it), fil, col-1, *direccion);
    ++it;
  }
}

int main(int argc, char * argv[]){
 if (argc != 4){
    cout << "Dime el fichero con la estructura jerarquica de las palabras " << endl;//Arbol_Ontologias.txt
    cout << "Dime el fichero con los significados" << endl; //significados.txt
    cout << "Dime el numero de palabras en la sopa" << endl;
    return 0;
 }

 Ontologias Ot;
 Ot.Lee(argv[1],argv[2]);

 int level;
 cout << endl << "Dime un nivel de tematica -> ";
 cin >> level;

 cout << "Las temáticas posibles a nivel " << level << " son:" << endl;
 Ontologias::iterator_level itl;
 int cnt = 1;
 for (itl = Ot.beginl(level); itl != Ot.endl(); ++itl){
   pair<set<string>,int> aux= *itl;
   set<string>::iterator sit = aux.first.begin();
   cout << "Temática " << cnt << " -> ";
   cnt++;
   while (sit!=aux.first.end()){
        cout << *sit << ", ";
        ++sit;
   }
   cout << endl;
 }

 int tema;

 PreguntasED Ask(Ot, level);

 cout << endl << "Escoge una de las tematicas posibles -> ";
 cin >> tema;

 Ask.SetTematica(tema-1);
 Ask.IniciaConceptosTemaEscogido();

 cout << endl << "**************************************" << endl;
 cin.get();

 Ask.BarajarPreguntas();

 Sopa_Letras misopa;
 misopa.SetTitulo(Ask.GetTitleTematica());
 set<string> aux;

 imprimeDefiniciones(Ask, aux);
 ponePalabraEnSopa(misopa, aux);

 while (misopa.Numero_Palabras()!=0){
    cout << endl << misopa << endl;

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

    if (!misopa.Esta_Palabra(word,row,col,direccion)){
       cout << "LA PALABRA " << word << " NO ESTÁ" << endl;
    }
    else{
        cout  << endl << "LA PALABRA " << word << " ES CORRECTA."  << endl;
        misopa.Poner_Acertada(word, row, col, direccion);
        aux.erase(word);
    }

    imprimeDefiniciones(Ask,aux);
 }
 cout << endl << misopa << endl;
 cout << "¡SOPA DE LETRAS CONSEGUIDA!" << endl;


 return 0;
}
