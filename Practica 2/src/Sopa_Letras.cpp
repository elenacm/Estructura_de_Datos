/**
  * @file Sopa_Letras.cpp
  * @brief Implementación de la sopa de letras
  *
  */
#include "./Sopa_Letras.h"
#include "./Matriz_Dispersa.h"
#include <iostream>

using namespace std;

Sopa_Letras::Sopa_Letras(){
  nAcertadas = 0;
  nPendientes = 0;
}

bool Sopa_Letras::Esta_Palabra(string p, int i, int j,string d){
  bool encontrado = true;
  char *palabra_char = new char[palabras.size() + 1];
  strcpy(palabra_char, p.c_str());
  int indice = acertadas.size();

  if(d == "vd"){ //vertical abajo
    int ind = i;
    for(unsigned int l=0; l<p.size(); l++, ind++){
      acertadas.setElemento(ind, j, false);
      if(matriz.getElemento(ind, j) != palabra_char[l]){
        encontrado = false;
        acertadas.resize(indice);
      }
    }
  }
  else if(d == "vu"){ //vertical arriba
    int ind = i;
    for(unsigned int l = 0; l<p.size(); ind--, l++){
      acertadas.setElemento(ind, j, false);
      if(matriz.getElemento(ind, j) != palabra_char[l]){
        encontrado = false;
        acertadas.resize(indice);
      }
    }
  }
  else if(d == "hr"){ //horizontal derecha
    int ind = j;
    for(unsigned int l = 0; l<p.size(); ind++, l++){
      acertadas.setElemento(i, ind, false);
      if(matriz.getElemento(i, ind) != palabra_char[l]){
        encontrado = false;
        acertadas.resize(indice);
      }
    }
  }
  else if(d == "hl"){ //horizontal izquierda
    int ind = j;
    for(unsigned int l = 0; l<p.size(); ind--, l++){
      acertadas.setElemento(i, ind, false);
      if(matriz.getElemento(i, ind) != palabra_char[l]){
        encontrado = false;
        acertadas.resize(indice);
      }
    }
  }
  else if(d == "ddr"){ //diagonal abajo derecha
    int indj = j;
    int indi = i;
    for(unsigned int l = 0; l<p.size(); indi++, indj++,l++){
      acertadas.setElemento(indi, indj, false);
      if(matriz.getElemento(indi, indj) != palabra_char[l]){
        encontrado = false;
        acertadas.resize(indice);
      }
    }
  }
  else if(d == "ddl"){ //diagonal abajo izquierda
    int indj = j;
    int indi = i;
    for(unsigned int l = 0; l<p.size(); indi++, indj--,l++){
      acertadas.setElemento(indi, indj, false);
      if(matriz.getElemento(indi, indj) != palabra_char[l]){
        encontrado = false;
        acertadas.resize(indice);
      }
    }
  }
  else if(d == "dur"){ //diagonal arriba derecha
    int indj = j;
    int indi = i;
    for(unsigned int l = 0; l<p.size(); indi--, indj++,l++){
      acertadas.setElemento(indi, indj, false);
      if(matriz.getElemento(indi, indj) != palabra_char[l]){
        encontrado = false;
        acertadas.resize(indice);
      }
    }
  }
  else if(d == "dul"){ //diagonal arriba izquierda
    int indj = j;
    int indi = i;
    for(unsigned int l = 0; l<p.size(); indi--, indj--, l++){
      acertadas.setElemento(indi, indj, false);
      if(matriz.getElemento(indi, indj) != palabra_char[l]){
        encontrado = false;
        acertadas.resize(indice);
      }
    }
  }

  return encontrado;
}

bool Sopa_Letras::Esta_EnLista(string palabra){
  bool encontrado = false;

  for(int i = 0; i < palabra.size(); i++){
    if(palabras[i] == palabra)
      encontrado = true;
  }

  return encontrado;
}
