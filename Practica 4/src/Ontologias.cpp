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

}

bool Ontologias::lee_significados(const char * fich_sig){

}

bool Ontologias::Lee(const char * fich_jerarquia,cons char * fic_significados){

}

bool Ontologias::Escribe(const char * fich_jerarquia,cons char * fic_significados){

}
