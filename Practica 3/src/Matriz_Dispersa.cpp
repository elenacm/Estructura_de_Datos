#include <iostream>
#include <string>
#include <list>

//Constructor por defecto
template <class T>
Matriz_Dispersa<T>::Matriz_Dispersa(){}

template <class T>
Matriz_Dispersa<T>::Matriz_Dispersa(T valor){
  valor_defecto = valor;
}

//Borra un elemento de la matriz
template <class T>
void Matriz_Dispersa<T>::borrar(int fila,int col){
  typename list<tripleta<T>>::iterator it;
  for(it=m.begin();it != m.end();it++){
    if((*it).fila == fila && (*it).col == col){
      it = m.erase(it);
    }
  }
}

template<typename T>
pair<bool, typename list<tripleta<T>>::iterator> Matriz_Dispersa<T>::posicion_indice(int i, int j){
  typename list<tripleta<T>>::iterator it = m.begin();

  while(it!=m.end()){
    if((*it).fila == i && (*it).col == j){
      return pair<bool, typename list<tripleta<T>>::iterator> (true, it);
    }
    it++;
  }
  it=m.begin();
  return  pair<bool, typename list<tripleta<T>>::iterator> (false,it);

}

template<typename T>
list<tripleta<T>> Matriz_Dispersa<T>::getMatriz(){
  return m;
}

//Modificador del elemento (i,j)
template <class T>
void Matriz_Dispersa<T>::append(int i, int j, T valor){
  //cout << "Introduciendo dato en fila " << i << " y columna " << j << endl;
  bool encontrado = false;

  pair <bool, typename list<tripleta<T>>::iterator > posicion = posicion_indice(i, j);
  if(!posicion.first){
    if(posicion.first){
      encontrado = true;
      m.erase(posicion.second);
    }
  }
  else{
    pair <bool, typename list<tripleta<T>>::iterator > posicion = posicion_indice(i, j);
    if(posicion.first){
      encontrado = true;
      (*posicion.second).d = valor;
    }
  }

  if(!encontrado){
    tripleta<T> t;
    t.fila = i;
    t.col = j;
    t.d = valor;
    m.push_back(t);
  }
}

//Comprobar si la palabra es acertada
template<class T>
bool Matriz_Dispersa<T>::estaAcertada(int fila,int columna){
  typename list<tripleta<T>>::iterator it;

  for(it=m.begin();it != m.end();it++){
    if((*it).fila == fila && (*it).col == columna){
      return true;
    }
  }
  return false;
}

//Consultor del elemento (i,j)
template <class T>
T Matriz_Dispersa<T>::getElemento(int fil, int col){
  T dato = valor_defecto;

  for(auto it : m){
    if(it.fila == fil && it.col == col)
      dato = it.d;
  }

  return dato;
}

//Consultor menor fila
template <class T>
int Matriz_Dispersa<T>::getMenor_Fila(){
  int menor_f = INT_MAX;

  for(auto it : m){
    if(menor_f > it.fila)
      menor_f = it.fila;
  }

  return menor_f;
}

//Consultor mayor fila
template <class T>
int Matriz_Dispersa<T>::getMayor_Fila(){
  int mayor_f = INT_MIN;

  for(auto it : m){
    if(mayor_f < it.fila)
      mayor_f = it.fila;
  }

  return mayor_f;
}

//Consultor menor columna
template <class T>
int Matriz_Dispersa<T>::getMenor_Columna(){
  int menor_c = INT_MAX;

  for(auto it : m){
    if(menor_c > it.col)
      menor_c = it.col;
  }

  return menor_c;
}

//Consultor mayor columna
template <class T>
int Matriz_Dispersa<T>::getMayor_Columna(){
    int mayor_c = INT_MIN;

    for(auto it : m){
      if(mayor_c < it.col)
        mayor_c = it.col;
    }

    return mayor_c;
}

//Consultor Valor por defecto
template <class T>
T Matriz_Dispersa<T>::get_Valor_Defecto(){
  return valor_defecto;
}

//Consultor casillas sin valor por defecto
template <class T>
int Matriz_Dispersa<T>::Casillas_Sin_Valor_Defecto(){
  int casillas = 0;

  for(auto it : m){
    if(it.d != valor_defecto)
      casillas++;
  }

  return casillas;
}

//Consultor filas de la matriz
template <class T>
int Matriz_Dispersa<T>::getFilas(){
  return (getMayor_Fila() - getMenor_Fila());
}

//Consultor columnas de la matriz
template <class T>
int Matriz_Dispersa<T>::getColumnas(){
  return (getMayor_Columna() - getMenor_Columna());
}
