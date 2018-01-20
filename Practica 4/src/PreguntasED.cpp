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

void PreguntasED::IniciaConceptosTemaEscogido(){
  string palabra = GetTitleTematica();
  Ontologias::iterator_level it_level = temas[tematica_escogida];
  Ontologias::iterator_level it;
  Ontologias::iterator inicio(it_level);
  Ontologias::iterator fin;

  if(tematica_escogida == temas.size()-1){
    fin = Ot.end();
  }
  else{
    it = temas[tematica_escogida+1];
    fin = Ontologias::iterator(it);
  }

  while(inicio != fin){
    preguntas_tema.push_back(inicio);
    ++inicio;
  }
}

void PreguntasED::BarajarPreguntas(){
  random_shuffle(preguntas_tema.begin(), preguntas_tema.end());
}

pair<set<string>,string> PreguntasED::SacaPregunta(){
  return GetPregunta(next_pregunta);
}

pair<set<string>,string> PreguntasED::GetPregunta(int i){
  pair<set<string>,string> aux;
  Ontologias::iterator it = preguntas_tema[i];
  pair<set<string>,int> par = *it;
  aux.first = par.first;

  aux.second = Ot.GetDefinicion(par.second);

  preguntas_hechas.insert(par.second);
  next_pregunta++;

  return aux;
}
