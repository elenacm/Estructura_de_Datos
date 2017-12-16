#include "Diccionario.h"
#include "Matriz_Dispersa.h"
#include <iostream>
#include <map>
#include <string>
#include <stdlib.h>

using namespace std;

void Diccionario::Borrar(const string &palabra){
  multimap<string,string>::iterator it = datos.find(palabra);

  datos.erase(it);
}

list<string> Diccionario::BuscaDef(const string &palabra) const{
  typedef multimap<string,string>::const_iterator iterator;
  pair<iterator,iterator> rango = datos.equal_range(palabra);

  list<string> r;

  for(iterator it = rango.first; it != rango.second; ++it){
    r.push_back(it->second);
  }
  return r;
}

unsigned int Diccionario::contabiliza(const string &palabra){
  return datos.count(palabra);
}

Diccionario Diccionario::ObtainPalabrasconDeficionContiene(string palabra){
  Diccionario aux;
  typename multimap<string,string>::iterator it = datos.begin();

  for(; it != datos.end(); ++it){
    if((*it).second.find(palabra) != std::string::npos)
      aux.datos.insert(*it);
  }

  return aux;
}

  multimap<string, string> Diccionario::getMultimap()const{
    return datos;
  }

  Sopa_Letras Diccionario::getSopa(){
    return sopa;
  }

  Diccionario Diccionario::escogePalabras(int b){
    Diccionario d;
    multimap<string, string>::const_iterator it;

    int cont = 0;

    while(cont < b){
      int cont2 = 0;
      int num;
      num = 0+rand() % datos.size();

      for(it=datos.begin(); it!=datos.end() && cont2<=num; it++){
        cont2++;
      }
      d.datos.insert(*it);   //Meto en el nuevo diccionario la palabra
      cont++;
    }
    return d;
  }

  void Diccionario::ponePalabraEnSopa(){
    multimap<string, string>::iterator it = datos.begin();

    list<string> direcciones ;
    direcciones.push_back("vu");
    direcciones.push_back("vd");
    direcciones.push_back("hd");
    direcciones.push_back("hi");
    direcciones.push_back("dd");
    direcciones.push_back("di");


    int fil, col, n_dir;
    list<string>::iterator direccion;
    srand(time(NULL));
    while(it!=datos.end()){

      do{

        fil = rand()%10;
        col = rand()%10;
        n_dir = rand()%6; //Elijo una de las 6 opciones que van desde 0 a 5

        int cont=0;
        for(direccion=direcciones.begin(); cont<n_dir; direccion++)
          cont++;
      }while(!sopa.Esta_Palabra((*it).first, fil, col-1, *direccion));

      sopa.addPalabra((*it).first, fil, col-1, *direccion);
      it++;
    }
  }
