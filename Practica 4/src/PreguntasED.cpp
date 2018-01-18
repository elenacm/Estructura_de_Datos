#include "PreguntasED.h"
using namespace std;

void PreguntasED::CreaTematica(){
  Ontologias::iterator_level it_level;

  for(it_level = Ot.beginl(tema_level); it_level != Ot.endl(); ++it_level){
    temas.push_back(it_level);
  }
}

void PreguntasED::MuestraTematicas(){
  vector<Ontologias::iterator_level>::iterator it_vector;
  set<string>::iterator it_set;

  for(it_vector = temas.begin(); it_vector != temas.end(); ++it_vector){
    std::cout << (*(*it_vector)).first;
  }

}

void PreguntasED::SetTematica(int i){
  tematica_escogida = i;
  next_pregunta = 0;
}

string PreguntasED::GetTitleTematica(){
  vector<Ontologias::iterator_level>::iterator it_level;
  set<string>::iterator it_set;
  bool encontrado = false;
  int count = 0;
  string palabra = "hola";

  for(it_level = temas.begin(); it_level != temas.end(); ++it_level){
    for(it_set = (*(*it_level)).first.begin(); it_set != (*(*it_level)).first.end() && !encontrado; ++it_set){
      if(count == tematica_escogida){
        palabra = (*it_set);
        encontrado = true;
      }
      else{
        count++;
      }
    }
  }

  return palabra;
}

/**
 *@brief Almacena todos las definiciones de las tematica escogida
 *@post tras la ejecución el miembro preguntas_tema tiene  las preguntas (significados de las palabras finales)
 *de la temática escogida. Además next_pregunta a 0 tienen un valor 0
 *
 */
void PreguntasED::IniciaConceptosTemaEscogido(){
  string palabra = GetTitleTematica();

  

}

void PreguntasED::BarajarPreguntas(){

}

/**
 *@brief Devuelve la siguiente pregunta a realizar
 *@post next_pregunta se modifica a la siguiente pregunta.
 */
pair<set<string>,string> PreguntasED::SacaPregunta(){

}

/**
 *@brief Obtiene una pregutna
 *@param i: indice de la pregunta a devolver
 *@return un para con con el conjunto de palabras sinonimos que responden a esa pregunta y la definición.
 */
pair<set<string>,string> PreguntasED::GetPregunta(int i){

}
