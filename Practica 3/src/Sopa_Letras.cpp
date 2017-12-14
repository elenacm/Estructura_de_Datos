/**
  * @file Sopa_Letras.cpp
  * @brief Implementación de la sopa de letras
  *
  */
#include "Sopa_Letras.h"
#include "Matriz_Dispersa.h"
#include <iostream>
#include <string>

using namespace std;

Sopa_Letras::Sopa_Letras(){
  nAcertadas = 0;
  nPendientes = 0;
}

bool Sopa_Letras::Esta_Palabra(string p, int i, int j,string d){
  bool comprobar_esta_en_lista = true;
  char *palabra_char = new char[p.length() + 1];
  strcpy(palabra_char, p.c_str());

  if(d == "vd"){ //vertical abajo
    int ind = i;
    for(unsigned int l=0; l < p.length(); l++, ind++){
      acertadas.append(ind, j, false);
      if(matriz.getElemento(ind, j) != palabra_char[l]){
        comprobar_esta_en_lista = false;
      }
    }
  }
  else if(d == "vu"){ //vertical arriba
    int ind = i;
    for(unsigned int l = 0; l < p.length(); ind--, l++){
      acertadas.append(ind, j, false);
      if(matriz.getElemento(ind, j) != palabra_char[l]){
        comprobar_esta_en_lista = false;
      }
    }
  }
  else if(d == "hd"){ //horizontal derecha
    int ind = j;
    for(unsigned int l = 0; l < p.length(); ind++, l++){
      acertadas.append(i, ind, false);
      if(matriz.getElemento(i, ind) != palabra_char[l]){
        comprobar_esta_en_lista = false;
      }
    }
  }
  else if(d == "hi"){ //horizontal izquierda
    int ind = j;
    for(unsigned int l = 0; l < p.length(); ind--, l++){
      acertadas.append(i, ind, false);
      if(matriz.getElemento(i, ind) != palabra_char[l]){
        comprobar_esta_en_lista = false;
      }
    }
  }
  else if(d == "dd"){ //diagonal abajo derecha
    int indj = j;
    int indi = i;
    for(unsigned int l = 0; l < p.length(); indi++, indj++,l++){
      acertadas.append(indi, indj, false);
      if(matriz.getElemento(indi, indj) != palabra_char[l]){
        comprobar_esta_en_lista = false;
      }
    }
  }
  else if(d == "di"){ //diagonal abajo izquierda
    int indj = j;
    int indi = i;
    for(unsigned int l = 0; l < p.size(); indi++, indj--,l++){
      acertadas.append(indi, indj, false);
      if(matriz.getElemento(indi, indj) != palabra_char[l]){
        comprobar_esta_en_lista = false;
      }
    }
  }

  if(comprobar_esta_en_lista){
    cout << "Comprobando si está en lista" << endl << flush;
    if(!Esta_EnLista(p)){
      cout << "No está la palabra" << endl;
      comprobar_esta_en_lista = false;
    }
    else{
      nAcertadas++;
      nPendientes--;
    }
  }

  return comprobar_esta_en_lista;
}

bool Sopa_Letras::Esta_EnLista(string palabra){

  for(auto it : palabras_ocultas){
    if(strcmp(it.data(), palabra.data()) == 0)
      return true;
  }

  return false;
}

bool Sopa_Letras::addPalabra(string palabra, int i, int j, string d){
	bool puedeInsertarse = true;
	char * palabra_char = new char[palabra.length() + 1];
	strcpy(palabra_char, palabra.c_str());
	palabras_ocultas.push_back(palabra);

	if(d == "hi"){ // horizontal izquierda
		int inc = j;
		for (unsigned int l = 0; l < palabra.length(); l++, inc--){
			if(matriz.getElemento(i,inc) != matriz.get_Valor_Defecto() && matriz.getElemento(i,inc) != palabra_char[l]){
				puedeInsertarse = false;
			}
		}
		if(puedeInsertarse){
			for (unsigned int l = 0; l < palabra.length(); l++ ,j--){
				matriz.append(i,j,palabra_char[l]);
			}
		}
	}
	else if (d == "hd"){ // horizontal derecha
		int inc = j;
		for (unsigned int l = 0; l < palabra.length(); l++, inc++){
			if(matriz.getElemento(i,inc) != matriz.get_Valor_Defecto() && matriz.getElemento(i,inc) != palabra_char[l]){
				puedeInsertarse = false;
			}
		}
		  if(puedeInsertarse){
			     for (unsigned int l = 0; l < palabra.length(); l++, j++){
				         matriz.append(i,j,palabra_char[l]);
			     }
      }
		}
		else if (d == "vu"){ // vertical arriba
			int inc = i;
			for (unsigned int l = 0; l < palabra.length(); l++, inc--){
				if(matriz.getElemento(inc,j) != matriz.get_Valor_Defecto() && matriz.getElemento(inc,j) != palabra_char[l]){
					puedeInsertarse = false;
				}
			}
			if(puedeInsertarse){
				for (unsigned int l = 0; l < palabra.length(); l++, i--){
					matriz.append(i,j,palabra_char[l]);
				}
			}
		}
		else if (d == "vd"){ // vertical abajo
			int inc = i;
			for (unsigned int l = 0; l < palabra.length(); l++, inc++){
				if(matriz.getElemento(inc,j) != matriz.get_Valor_Defecto() && matriz.getElemento(inc,j) != palabra_char[l] && matriz.getElemento(inc,j) != '\0'){
					puedeInsertarse = false;
				}
			}
			if(puedeInsertarse){
				for (unsigned int l = 0; l < palabra.length(); l++, i++){
					matriz.append(i,j,palabra_char[l]);
				}
			}
		}
		else if (d == "dd"){ // diagonal abajo derecha
			int inci = i;
			int incj = j;
			for (unsigned int l = 0; l < palabra.length(); l++, inci++, incj++){
				if(matriz.getElemento(inci,incj) != matriz.get_Valor_Defecto() && matriz.getElemento(inci,incj) != palabra_char[l]){
					puedeInsertarse = false;
				}
			}
			if(puedeInsertarse){
				for (unsigned int l = 0; l < palabra.length(); l++, i++, j++){
					matriz.append(i,j,palabra_char[l]);
				}
			}
		}
		else if (d == "di"){ // diagonal abajo izquierda
			int inci = i;
			int incj = j;
			for (unsigned int l = 0; l < palabra.length(); l++, inci++, incj--){
				if(matriz.getElemento(inci,incj) != matriz.get_Valor_Defecto() && matriz.getElemento(inci,incj) != palabra_char[l]){
					puedeInsertarse = false;
				}
			}
			if(puedeInsertarse){
				for (unsigned int l = 0; l < palabra.length(); l++, i++, j--){
					matriz.append(i,j,palabra_char[l]);
				}
			}
		}
		if(!puedeInsertarse) palabras_ocultas.pop_back();
		delete[] palabra_char;

    return puedeInsertarse;
	}
