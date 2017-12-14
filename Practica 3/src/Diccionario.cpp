#include "Diccionario.h"

using namespace std;

void Diccionario::Insertar(string palabra, string def){
  datos.insert(make_pair(palabra,def));
}

void Diccionario::Borrar(const string &palabra, const string &def){
  multimap<string,string>::iterator it = datos.find(palabra);

  datos.erase(it);

  it = datos.find(def);
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
  multimap<string,string>::iterator it = datos.begin();

  for(; it != datos.end(); ++it){
    if((it->second).find(palabra) != std::string::npos)
      aux.Insertar(it->first,it->second);
  }

  return aux;
}
