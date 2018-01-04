#include "Ontologias.h"
#include "ArbolGeneral.h"
#include <fstream>
using namespace std;

pair<bool, Ontologias::const_iterator> Ontologias::Esta(const string &o)const{
  ArbolGeneral<pair<set<string>,int>>::const_iter_preorden it;
  set<string>::const_iterator it_set;
  bool esta = false;
  Ontologias::const_iterator ci = end();
  pair<bool, Ontologias::const_iterator> mipair(esta,ci);

  for(it = ab.begin(); it != ab.end(); ++it){
    for(it_set = (*it).first.cbegin(); it_set != (*it).first.cend(); ++it_set){
      if((*it_set) == o){
        esta = true;
        //ci = Ontologias->(*it);
      }
    }
  }

  return mipair;
}

void Ontologias::clear(){
  significados.clear();
  ab.~ArbolGeneral();
  n_palabras = 0;
}

map<string,set<string> > Ontologias::GetSinonimos(const string & palabra)const{
  map<string,set<string>> sinonimos;
  ArbolGeneral<pair<set<string>,int>>::const_iter_preorden it;
  set<string>::iterator its;
  map<int, string>::const_iterator it_sign;
  string sign;

  for(it = ab.begin(); it != ab.end(); ++it){
    if((*it).second != -1){
      for(its = (*it).first.begin(); its != (*it).first.end(); ++its){
        if((*its) == palabra){
          for(it_sign = significados.begin(); it_sign != significados.end(); ++it_sign){
            if((*it_sign).first == (*it).second)
              sign = (*it_sign).second;
          }
          sinonimos.insert(pair<string,set<string>>(sign, (*it).first));
        }
      }
    }
  }

  return sinonimos;
}

list<set<string> > Ontologias::GetSuperPalabra(const string & palabra,const string & signifi)const{
  list<set<string>> lista_inicial;
  ArbolGeneral<pair<set<string>,int>>::const_iter_preorden it;
  set<string>::const_iterator it_set;
  Ontologias::iterator it_onto;

  for(it = ab.begin(); it != ab.end(); ++it){
    if((*it).second != -1){
      for(it_set = (*it).first.begin(); it_set != (*it).first.end(); ++it_set){
        if((*it_set) == palabra){
          lista_inicial = it_onto.GetJerarquia();
        }
      }
    }
  }

  return lista_inicial;
}

string Ontologias::GetDefinicion(int pos){
  string n;
  map<int,string>::iterator it;

  for(it = significados.begin(); it != significados.end(); it++){
    if((*it).first == pos)
      return (*it).second;
  }

  return n;
}

bool Ontologias::lee_significados(const char * fich_sig){
  pair<int,string> insertado;
  ifstream f(fich_sig);
  bool leido = false;

  while(!f.eof()){
    f >> insertado.first;
    getline(f, insertado.second, '\n');

    significados.insert(insertado);
    leido = true;
  }

  return leido;
}

bool Ontologias::Lee(const char * fich_jerarquia,const char * fic_significados){
  bool leido = false;
  ifstream fj(fich_jerarquia);
  int nodo, n_sign;
  char n;

  while(!fj.eof()){

    if(lee_significados(fic_significados))
      leido = true;
  }

  return leido;
}

bool Ontologias::Escribe(const char * fich_jerarquia,const char * fic_significados){
  bool escrito = false;



  return escrito;
}
