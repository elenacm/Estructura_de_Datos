#include "Ontologias.h"
#include <iostream>
using namespace std;

pair<bool, Ontologias::const_iterator> Ontologias::Esta(const string &o)const{
  const_iterator it;
  set<string>::const_iterator it_set;
  bool esta = false;

  for(it = begin(); it != end() && !esta; ++it){
    for(it_set = (*it).first.cbegin(); it_set != (*it).first.cend() && !esta; ++it_set){
      if((*it_set) == o)
        esta = true;
    }
  }

  return pair<bool, const_iterator>(esta,it);
}

void Ontologias::clear(){
  significados.clear();
  ab.~ArbolGeneral();
  n_palabras = 0;
}

map<string,set<string> > Ontologias::GetSinonimos(const string & palabra)const{
  map<string,set<string>> sinonimos;
  const_iterator it;
  set<string>::iterator its;
  map<int, string>::const_iterator it_sign;
  string sign;

  for(it = begin(); it != end(); ++it){
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
  const_iterator it;
  set<string>::const_iterator it_set;
  iterator it_onto;

  for(it = begin(); it != end(); ++it){
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

  for(it = significados.begin(); it != significados.end(); ++it){
    if((*it).first == pos)
      return (*it).second;
  }

  return n;
}

bool Ontologias::lee_significados(const char * fich_sig){
  fstream f(fich_sig);
  char espacio;
  string def;
  int numero;

  while(!f.eof()){
    f >> numero;
    f >> espacio;
    getline(f, def, '\n');
    significados.insert(pair<int,string>(numero,def));
    return true;
  }

  return false;
}

bool Ontologias::Lee(const char * fich_jerarquia,const char * fic_significados){
  ifstream f(fich_jerarquia);
  n_palabras = 0;
  bool leido = lee_significados(fic_significados);
  iterator it;
  set<string>::iterator it_set;

  f >> ab;

  for(it = begin(); it != end(); ++it){
    if((*it).second != -1){
      for(it_set = (*it).first.begin(); it_set != (*it).first.end(); ++it_set){
        n_palabras++;
      }
    }
  }

  if(leido){
    std::cout << "Todo leído correctamente :)" << std::endl;
    std::cout << "Hay " << n_palabras << " palabras finales :)" << std::endl;
  }
  else
    std::cout << "Error de lectura :(" << std::endl;

  return leido;
}

bool Ontologias::Escribe(const char * fich_jerarquia,const char * fic_significados){
  map<int,string>::iterator it_map;
  fstream fj(fich_jerarquia);
  fstream fs(fic_significados);

  if(fj && fs){
    fj << ab;
    for(it_map = significados.begin(); it_map != significados.end(); ++it_map){
      fs << (*it_map).first;
      fs << " ";
      fs << (*it_map).second << flush;
    }

    return true;
  }

  return false;
}
