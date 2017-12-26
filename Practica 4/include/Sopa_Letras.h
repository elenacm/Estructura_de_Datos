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
      * @return Crea un objeto de la clase Sopa de Letras
      */
    Sopa_Letras(){}

    /**
      * @brief Consultor de las palabras ocultas
      * @return Devuelve el tamaño de las palabras_ocultas
      */
    int Numero_Palabras(){ return palabras_ocultas.size(); }

    /**
      * @brief Consultor del tamaño de la matriz
      * @return Devuelve el tamaño de la matriz
      */
    int size(){ return matriz.size(); }

    /**
      * @brief Consultor del nombre de la sopa de letras
      * @return devuelve el nombre
      */
    string getTitulo(){ return titulo; }

    /**
      * @brief Consultor de la mayor columna
      * @return Devuelve la mayor columna de la matriz
      */
    int getMayor_Columna(){ return matriz.getMayor_Columna(); }

    /**
      * @brief Consultor de las columnas
      * @return Devuelve el numero total de las columnas de la matriz
      */
    int getColumnas(){ return matriz.getColumnas(); }

    /**
      * @brief Consultor de las palabras acertadas
      * @return Devuelve el tamaño de las palabras acertadas
      */
    int getAcertadas(){ return palabras_descubiertas.size(); }

    /**
      * @brief Consultor de las palabras ocultas
      * @return Devuelve el tamaño de las palabras ocultas
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
      * @brief Metodo para colocar una palabra en la matriz
      * @param p palara que se va a colocar
      * @param i fila en la que se va a introducir
      * @param j columna en la que se va a introducir
      * @param d direccion en la que se va a colocar la palabra
      */
    bool addPalabra(string p, int i, int j, string d);

    /**
      * @brief Metodo que cambia una palabra oculta a descubierta
      * @param p palabra que se va a colocar
      * @param row fila en la que se va a introducir
      * @param col columna en la que se va a introducir
      * @param d direccion en la que se va a colocar la palabra
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
  				if(i>10 || i<0)
  					s << " " << i << "";
  				else
  					s << "  " << i << "";
  			}
  			s << '\n';

  			for(int i=sopa.matriz.getMenor_Fila();i<=sopa.matriz.getMayor_Fila();i++){
  				if(i < 0 || i > 9)
  					s << i << "|" << flush;
  				else
  					s << i << " |" << flush;
  				for(int j=sopa.matriz.getMenor_Columna();j<=sopa.matriz.getMayor_Columna();j++){
  					if(sopa.matriz.getElemento(i,j) != sopa.matriz.get_Valor_Defecto()){
  						if(sopa.acertadas.getElemento(i,j) != '\0'){
  							s << " " << "\e[1m" <<(char)(toupper(sopa.matriz.getElemento(i,j))) << "\e[0m" << " ";
              }
  						else
  							s << " " << (char)(toupper(sopa.matriz.getElemento(i,j))) << " ";
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
  		friend istream& operator>>(istream& is, Sopa_Letras &sopa){
        string nombre, direccion, palabra;
        int fil, col;
        sopa.matriz.getMatriz().clear();

        getline(is, nombre);
        sopa.SetTitulo(nombre);

        while(is >> fil >> col >> direccion >> palabra){
          if(sopa.Esta_Palabra(palabra, fil, col, direccion)){}
        }
        return is;
      }
  };

  #endif
