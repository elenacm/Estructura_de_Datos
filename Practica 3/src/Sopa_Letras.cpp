/**
  * @file Sopa_Letras.cpp
  * @brief Implementación de la sopa de letras
  */
#include <iostream>
#include <string>
#include <list>
#include "Sopa_Letras.h"

using namespace std;

Sopa_Letras::Sopa_Letras(){}

bool Sopa_Letras::Esta_Palabra(string p, int i, int j,string d){
  bool correcto = true;
  pair<bool, typename list<tripleta<char>>::iterator > posicion = matriz.posicion_indice(i, j);
  unsigned int cont=0;

  if(d == "vu"){     // Vertical arriba
    while(cont < p.length() && correcto){
      if(posicion.first && (*posicion.second).d != p[cont])
        correcto = false;
      cont++;
      --i;
      posicion = matriz.posicion_indice(i, j);
    }
  }

  else if(d == "vd"){    // Vertical abajo
    while(cont < p.length() && correcto){
      if(posicion.first && (*posicion.second).d != p[cont])
        correcto = false;
      cont++;
      ++i;
      posicion = matriz.posicion_indice(i, j);
    }
  }

  else if(d == "hi"){     // horizontal izquierda
    while(cont < p.length() && correcto){
      if(posicion.first && (*posicion.second).d != p[cont])
        correcto = false;
      cont++;
      --j;
      posicion = matriz.posicion_indice(i, j);
    }
  }

  else if(d == "hd"){     // horizontal derecha
    while(cont < p.length() && correcto){
      if(posicion.first && (*posicion.second).d != p[cont])
        correcto = false;
      cont++;
      ++j;
      posicion = matriz.posicion_indice(i, j);
    }
  }

  else if(d == "dd"){     // Diagonal abajo derecha
    while(cont < p.length() && correcto){
      if(posicion.first && (*posicion.second).d != p[cont])
        correcto = false;
      cont++;
      ++i;
      ++j;
      posicion = matriz.posicion_indice(i, j);
    }
  }

  else if(d == "di"){     // Diagonal abajo izquierda (di)
    while(cont < p.length() && correcto){
      if(posicion.first && (*posicion.second).d != p[cont])
        correcto = false;
      cont++;
      ++i;
      --j;
      posicion = matriz.posicion_indice(i,j);
    }
  }

  else correcto = false;

  return correcto;
}

void Sopa_Letras::Poner_Acertada(string p, int row, int col, string d){
  typename list<string>::iterator it = palabras_ocultas.begin();
  while((*it) != p)
    it++;

  palabras_ocultas.erase(it); // quitada de no_descubiertas
  palabras_descubiertas.push(p);   // la pongo en la primera posicion de descubiertas
  Colocar_Acertada(p, row, col,d);
}

void Sopa_Letras::Colocar_Acertada(string p, int i, int j, string d){
   pair<bool, typename list<tripleta<char>>::iterator > pos = acertadas.posicion_indice(i, j);
   list<tripleta<char>>::iterator it = acertadas.getMatriz().begin();
   unsigned int cont=0;
   if(d == "vu"){     //Vertical Arriba
      while(cont < p.length()){
        if(!pos.first){
          tripleta<char> t;
          t.fila = i;
          t.col = j;
          t.d = p[cont];
          acertadas.append(t.fila, t.col, t.d);
        }

        cont++;
        --i;
        pos = acertadas.posicion_indice(i, j);

      }
   }
   else if(d == "vd"){    // Vertical abajo
      while(cont < p.length()){
        if(!pos.first){
          tripleta<char> t;
          t.fila = i;
          t.col = j;
          t.d = p[cont];
          acertadas.append(t.fila, t.col, t.d);
        }

        cont++;
        ++i;
        pos = acertadas.posicion_indice(i, j);
      }
   }
   else if(d == "hi"){   // horizontal izquierda
      while(cont < p.length()){
        if(!pos.first){
          tripleta<char> t;
          t.fila = i;
          t.col = j;
          t.d = p[cont];
          acertadas.append(t.fila, t.col, t.d);
        }

        cont++;
        --j;
        pos = acertadas.posicion_indice(i, j);
      }
   }
   else if(d == "hd"){   // horizontal derecha
      while(cont < p.length()){
        if(!pos.first){
          tripleta<char> t;
          t.fila = i;
          t.col = j;
          t.d = p[cont];
          acertadas.append(t.fila, t.col, t.d);
        }

        cont++;
        ++j;
        pos = acertadas.posicion_indice(i, j);
      }
   }

   else if(d == "dd"){    // Diagonal abajo derecha
     while(cont < p.length()){
       if(!pos.first){
         tripleta<char> t;
         t.fila = i;
         t.col  = j;
         t.d    = p[cont];
         acertadas.append(t.fila, t.col, t.d);
       }

       cont++;
       ++i;
       ++j;
       pos = acertadas.posicion_indice(i,j);
     }
   }

   else if(d == "di"){   // Diagonal abajo izquierda
     while(cont < p.length()){
        if(!pos.first){
          tripleta<char> t;
          t.fila = i;
          t.col = j;
          t.d = p[cont];
          acertadas.append(t.fila, t.col, t.d);
        }

        cont++;
        ++i;
        --j;
        pos = acertadas.posicion_indice(i,j);
      }
   }
   acertadas.getMatriz().sort();
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
