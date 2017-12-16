/**
  * @file Sopa_Letras.h
  * @brief Fichero cabecera del TDA
  *
  */

#ifndef _SOPA_LETRAS_H
#define _SOPA_LETRAS_H

#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <cctype>
#include <stdio.h>
#include <string.h>
#include <list>
#include <queue>
#include "Matriz_Dispersa.h"

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
    Matriz_Dispersa<char> acertadas; /**< matriz para ver las palabras acertadas */
    list<string> palabras_ocultas; /**< palabras cargadas */
    queue<string> palabras_descubiertas; /**< palabras acertadas() */

  public:

    /**
      * @brief Constructor por defecto
      * Crea un objeto de la clase Sopa de Letras
      */
    Sopa_Letras();

    /**
      * @brief Obtiene el numero de palabras ocultas
      */
    int Numero_Palabras(){ return palabras_ocultas.size(); }

    /**
      * @brief Obtiene el tamaño de la matriz
      */
    int size(){ return matriz.size(); }

    /**
      * @brief Obtiene el nombre de la sopa de letras
      */
    string getTitulo(){ return titulo; }

    /**
      * @brief Obtiene la mayor columna
      */
    int getMayor_Columna(){ return matriz.getMayor_Columna(); }

    /**
      * @brief Obtiene el numero total de columnas
      */
    int getColumnas(){ return matriz.getColumnas(); }

    /**
      * @brief Obtiene el numero de palabras acertadas
      */
    int getAcertadas(){ return palabras_descubiertas.size(); }

    /**
      * @brief Obtiene el numero de palabras ocultas
      */
    int getPendientes(){ return palabras_ocultas.size(); }

    /**
      * @brief Modifica el titulo de la sopa de letras
      */
    void SetTitulo(string n){ titulo = n; }

    /**
      * @brief Comprueba si ha acertado una palabra
		  * @param p La palabra que se quiere comprobar
		  * @param i la fila en la que empieza
		  * @param j la columna en la que empieza
		  * @param d la dirección en que debe leerse
      * @return devuelve si la palabra esta en la sopa de letras
      */
    bool Esta_Palabra(string p, int i, int j,string d);

  	/**
  		* @brief Incluir una palabra en la matriz
  		* @param p La palabra a incluir
      * @param i fila
      * @param j columna
      * @param d direccion en la que se encuentra la palabra
  		*/
  	void Poner_Palabra(string p, int i, int j, string d){ palabras_descubiertas.push(p); }

    /**
    	* @brief Comprueba que la sucesión de letras que ha introducido corresponde a una palabra de la lista
  		* @param palabra La palabra que se quiere comprobar
      * @return Devuelve si la palabra esta en la lista
  		*/
		bool Esta_EnLista(string palabra);

    /**
      *
      */
    void Colocar(string p, int i, int j, string d);

    /**
      *
      */
    void Poner_Acertada(string p, int row, int col, string d);

    /**
      * @brief Coloca una palabra en la matriz de acertadas
      * @param p palabra que se ha acertado
      * @param i fila
      * @param j columna
      * @param d direccion en que se va a colocar la palabra
      */
    void Colocar_Acertada(string p, int i, int j, string d);


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
  			s << "Titulo: " << sopa.getTitulo() << endl << flush;
        s << "Numero de palabras ocultas -> " << sopa.getPendientes() << endl;
        s << "Palabras descubiertas -> " << sopa.getAcertadas() << endl;

        s << "  " << flush;
  			for(int i=sopa.matriz.getMenor_Columna();i<=sopa.matriz.getMayor_Columna();i++){
  				if(i<10 || i<0)
  					s << " " << i << "";
  				else
  					s << "  " << i << " ";
  			}
  			s << '\n';

  			for(int i=sopa.matriz.getMenor_Fila();i<=sopa.matriz.getMayor_Fila();i++){
  				if(i < 0 || i > 9)
  					s << i << "|" << flush;
  				else
  					s << i << " |" << flush;
  				for(int j=sopa.matriz.getMenor_Columna();j<=sopa.matriz.getMayor_Columna();j++){
  					if(sopa.matriz.getElemento(i,j) != sopa.matriz.get_Valor_Defecto()){
  						if(sopa.matriz.getElemento(i,j) != '\0'){
  							s << " " <<(char)(toupper(sopa.matriz.getElemento(i,j))) << " ";
              }
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
  		friend istream& operator>>(istream& is, Sopa_Letras &s){
        string nombre, direccion, palabra;
        int fil, col;
        s.matriz.getMatriz().clear();

        getline(is, nombre);
        s.SetTitulo(nombre);

        while(is >> fil >> col >> direccion >> palabra){
          if(s.Esta_Palabra(palabra, fil, col, direccion)){}
        }
        return is;
      }
  };

  #endif
