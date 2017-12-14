/**
  * @file Sopa_Letras.h
  * @brief Fichero cabecera del TDA
  *
  */

#ifndef _SOPA_LETRAS_H
#define _SOPA_LETRAS_H

#include <iostream>
#include "Matriz_Dispersa.h"
#include <sstream>
#include <cctype>
#include <stdio.h>
#include <string.h>
#include <list>
#include <queue>

using namespace std;

/**
  * @brief T.D.A. Sopa de Letras
  *
  * Una instancia @c del tipo abstracto @c Sopa de Letrascontiene un conjunto de palabras
  * dispuesto de las direcciones verticales, horizontal o diagonal en una matriz dispersa.
  *
  * [{fila1,columna1,letra},...,{filaN,columnaN,valorN}]
  *
  * Un ejemplo de su uso se encuentra en:
  * @include prueba_sp.cpp
  *
  * @author Elena Cantero Molina
  * @date Noviembre 2017
  */

class Sopa_Letras{
  /**
    * @page repConjunto Rep del TDA Sopa de Letras
    *
    * @section invConjunto Invariante de la representación
    *
    * El invariante es \e rep.matriz.size() > 0
    *
    * @section faConjunto Función de Abstracción
    *
    * Un objeto válido @e rep del TDA Sopa de Letras representa a la estructura
    *
    * rep.matriz[<0,0,'V'>,<0,1,'A'>..<i,j,'*'>]
    *
    */
  private:
    string titulo; /**< Título de la sopa de letras */
    Matriz_Dispersa<char> matriz; /**< Matriz Dispersa */
    Matriz_Dispersa<bool> acertadas; /**< matriz para ver las palabras acertadas */
    list<string> palabras_ocultas; /**< palabras cargadas */
    queue<string> palabras_descubiertas; /**< palabras acertadas() */
    int nAcertadas; /**< numero de palabras acertadas */
    int nPendientes; /**< numero de palabras pendientes */

  public:

    /**
      * @brief Constructor por defecto
      * Crea un objeto de la clase Sopa de Letras
      *
      */
    Sopa_Letras();

    /**
      * @brief Obtiene el numero de palabras ocultas
      *
      */
    int Numero_Palabras(){ return palabras_ocultas.size(); }

    /**
      * @brief Obtiene el tamaño de la matriz
      *
      */
    int size(){ return matriz.size(); }

    /**
      * @brief Obtiene el nombre de la sopa de letras
      *
      */
    string getTitulo(){ return titulo; }

    /**
      * @brief Obtiene la mayor columna
      *
      */
    int getMayor_Columna(){ return matriz.getMayor_Columna(); }

    /**
      * @brief Obtiene el numero total de columnas
      *
      */
    int getColumnas(){ return matriz.getColumnas(); }

    /**
      * @brief Obtiene el numero de palabras acertadas
      *
      */
    int getAcertadas(){ return nAcertadas; }

    /**
      * @brief Obtiene el numero de palabras pendientes
      *
      */
    int getPendientes(){ return nPendientes; }

    /**
      * @brief Comprueba si ha acertado una palabra
		  * @param p La palabra que se quiere comprobar
		  * @param i la fila en la que empieza
		  * @param j la columna en la que empieza
		  * @param d la dirección en que debe leerse
      * @return devuelve si la palabra esta en la sopa de letras
      *
      */
    bool Esta_Palabra(string p, int i, int j,string d);

  	/**
  		* @brief Incluir una palabra en la lista de acertadas
  		* @param p La palabra a incluir
      * @param i fila
      * @param j columna
      * @param d direccion en la que se encuentra la palabra
      *
  		*/
  	void Poner_Palabra(string p, int i, int j, string d){ palabras_descubiertas.push(p); }

    /**
    	* @brief Comprueba que la sucesión de letras que ha introducido corresponde a una palabra de la lista
  		* @param palabra La palabra que se quiere comprobar
      * @return Devuelve si la palabra esta en la lista
      *
  		*/
		bool Esta_EnLista(string palabra);

    /**
      * @brief
      * @param
      */
    bool addPalabra(string palabra, int i, int j, string d);

		/**
  		* @brief Sobrecarga del operador <<
  		* Imprime la sopa de letras
  		* @param s el flujo de salida
  		* @param sopa la referencia al objeto que llama al método
  		*/
		friend ostream & operator<<(ostream & s, Sopa_Letras & sopa){
  			if(sopa.matriz.getMenor_Columna() < 0 || sopa.matriz.getMenor_Columna() > 9)
  				s << "";
  			else
  				s << "";

  			s << " Titulo: " << sopa.getTitulo() << endl << flush;
        s << " Numero de palabras ocultas -> " << sopa.palabras_ocultas.size() << endl;
        s << " Palabras descubiertas -> " << sopa.getAcertadas() << endl;

        s << "    " << flush;
  			for(int i=sopa.matriz.getMenor_Columna();i<=sopa.matriz.getMayor_Columna();i++){
  				if(i<10 || i<0)
  					s << i << "  ";
  				else
  					s << i << " ";
  			}
  			s << '\n';
  			for(int i=sopa.matriz.getMenor_Fila();i<=sopa.matriz.getMayor_Fila();i++){
  				if(i < 0 || i > 9)
  					s << i << "|" << flush;
  				else
  					s << i << " |" << flush;
  				for(int j=sopa.matriz.getMenor_Columna();j<=sopa.matriz.getMayor_Columna();j++){
  					if(sopa.matriz.getElemento(i,j) != sopa.matriz.get_Valor_Defecto()){
  						if(sopa.acertadas.getElemento(i,j) != '\0')
  							s << " " << sopa.matriz.getElemento(i,j) << " ";
  						else
  							s << " " << sopa.matriz.getElemento(i,j) << " ";
  					} else {
  						char aleatorio = 65 + rand() % (90-65);
              s << " " << aleatorio << " " << flush;
  					}
  				}
  				s << '\n';
  			}
  			return s;
  		}

  		/**
  		* @brief Sobrecarga del operador >>
  		* Lee la sopa de letras a partir de un fichero. Comprueba que todas las palabras son aptas para introducir.
  		* Esto significa que si dos palabras se cruzan, ha de ser por una letra en común.
  		* @param is el flujo de entrada
  		* @param sopa la referencia al objeto que llama al método
  		*/
  		friend istream & operator>>(istream & is, Sopa_Letras & sopa) {
  			getline(is, sopa.titulo);
  			string line;
  			while (getline(is, line)){
  			    istringstream iss(line);
  			    int i, j;
  			    string d, palabra;

  			    if (!(iss >> i >> j >> d >> palabra)) { break; } // error
  			    //cout << "!! " << palabra << " i:" << i << endl;
  			    char * palabra_char = new char[palabra.length() + 1];
  				strcpy(palabra_char, palabra.c_str());
  				bool puedeInsertarse=true;

  		    	sopa.palabras_ocultas.push_back(palabra);
  			    if(d == "hi"){ // horizontal izquierda
  			    	int ind = j;
  			    	for (unsigned int l=0;l<palabra.length();l++,ind--){
  	    				if((sopa.matriz.getElemento(i,ind) != sopa.matriz.get_Valor_Defecto()) && (sopa.matriz.getElemento(i,ind) != palabra_char[l])){
  	    					puedeInsertarse=false;
  	    				}
  			    	}
  			    	if(puedeInsertarse)
  					    for (unsigned int l=0;l<palabra.length();l++,j--){
  		    				sopa.matriz.append(i,j,palabra_char[l]);
  					    }
  				}
  			    else if (d == "hd"){ // horizontal derecha
  			    	int ind=j;
  			    	for (unsigned int l=0;l<palabra.length();l++,ind++){
  	    				if((sopa.matriz.getElemento(i,ind) != sopa.matriz.get_Valor_Defecto()) && (sopa.matriz.getElemento(i,ind) != palabra_char[l])){
  	    					puedeInsertarse=false;
  	    				}
  			    	}
  			    	if(puedeInsertarse)
  				    	for (unsigned int l=0;l<palabra.length();l++,j++){
  		    				sopa.matriz.append(i,j,palabra_char[l]);
                }
  			    }
      			else if (d == "vu"){ // vertical arriba
      				int ind = i;
      				for (unsigned int l=0;l<palabra.length();l++,ind--){
  	    				if((sopa.matriz.getElemento(ind,j) != sopa.matriz.get_Valor_Defecto()) && (sopa.matriz.getElemento(ind,j) != palabra_char[l])){
  	    					puedeInsertarse=false;
  	    				}
  			    	}
  			    	if(puedeInsertarse)
  				    	for (unsigned int l=0;l<palabra.length();l++,i--){
  		    				sopa.matriz.append(i,j,palabra_char[l]);
  				    	}
  			    }
      			else if (d == "vd"){ // vertical abajo
      				int ind = i;
      				for (unsigned int l=0;l<palabra.length();l++,ind++){
  	    				if((sopa.matriz.getElemento(ind,j) != sopa.matriz.get_Valor_Defecto()) && (sopa.matriz.getElemento(ind,j) != palabra_char[l]) && (sopa.matriz.getElemento(ind,j) != '\0')){
  	    					puedeInsertarse=false;
  	    				}
  			    	}
  			    	if(puedeInsertarse)
  				    	for (unsigned int l=0;l<palabra.length();l++,i++){
  		    				sopa.matriz.append(i,j,palabra_char[l]);
  				    	}
  			    }
      			else if (d == "dd"){ // diagonal abajo derecha
      				int indi = i;
      				int indj = j;
      				for (unsigned int l=0;l<palabra.length();l++,indi++,indj++){
  	    				if((sopa.matriz.getElemento(indi,indj) != sopa.matriz.get_Valor_Defecto()) && (sopa.matriz.getElemento(indi,indj) != palabra_char[l])){
  	    					puedeInsertarse=false;
  	    				}
  			    	}
  			    	if(puedeInsertarse)
  				    	for (unsigned int l=0;l<palabra.length();l++,i++,j++){
  		    				sopa.matriz.append(i,j,palabra_char[l]);
  				    	}
  			    }
      			else if (d == "di"){ // diagonal abajo izquierda
      				int indi = i;
      				int indj = j;
      				for (unsigned int l=0;l<palabra.length();l++,indi++,indj--){
  	    				if((sopa.matriz.getElemento(indi,indj) != sopa.matriz.get_Valor_Defecto()) && (sopa.matriz.getElemento(indi,indj) != palabra_char[l])){
  	    					puedeInsertarse=false;
  	    				}
  			    	}
  			    	if(puedeInsertarse){
  				    	for (unsigned int l=0;l<palabra.length();l++,i++,j--){
  		    				sopa.matriz.append(i,j,palabra_char[l]);
  				    	}

  				    }
  			    }

  				delete[] palabra_char;

  			}

  		    return is;
  		}
  };

  #endif
