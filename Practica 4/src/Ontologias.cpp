#include "Ontologias.h"
#include "ArbolGeneral.h"
using namespace std;

pair<bool, const_iterator> Ontologias::Esta(const string &o)const{
  //Hay que recorrer el arbol General
}

//NO SE SI ESTO ESTA BIEN JEJE
void Ontologias::clear(){
  significados.clear();
  ~ArbolGeneral();
  n_palabras = 0;
}

map<string,set<string> > Ontologias::GetSinonimos(const string & palabra)const{
  //crear un map para guardar los sinonimos y significados
  //recorrer ArbolGeneral y map?
  //un iterador?
  //buscar sinonimos de palabra
  //introducir en el map sinonimos y significado
  //devolver map
}

list<set<string> > Ontologias::GetSuperPalabra(const string & palabra,const string & signifi)const{

}

string Ontologias::GetDefinicion(int pos){
  string n = "nada";
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

  while(!f.eof()){
    getline(f, insertado.first, ' ');
    getline(f, insertado.second, '\n');

    significados.insert(insertado);
  }
}

bool Ontologias::Lee(const char * fich_jerarquia,cons char * fic_significados){

}

bool Ontologias::Escribe(const char * fich_jerarquia,cons char * fic_significados){

}
