/**
  * @file Matriz_Dispersa.h
  * @brief Fichero cabecera del TDA Matriz Dispersa
  *
  */

#ifndef _MATRIZ_DISPERSA_H
#define _MATRIZ_DISPERSA_H

#include <iostream>
#include "./Vector_Dinamico.h"

using namespace std;
template <class T>

/**
  * @brief TDA Matriz Dispersa
  *
  * Un objeto de tipo matriz_dispersa es un array 1-d de tripletas
  * formadas por: una fila, columna y el valor asociado de tipo carácter.
  * Solamente se almacenan los valores con un valor diferente a un valor
  * por defecto (0)
  *
  *{(i0, j0, mi, j),(i1, j1, mi, j),...,(in−1, jn−1, min−1,jn−1),(∗, d)}
  *
  * Un ejemplo de su uso es:
  * @include prueba.cpp
  *
  * @author Elena Cantero Molina
  * @date Noviembre 2017
  */

  class Matriz_Dispersa{

    /**
      *
      * @page repConjunto Rep del TDA Matriz Dispersa
      *
      * @section invConjunto Invariante de la representación
      *
      * El invariante es \e rep.tripleta!=0
      *
      * @section faConjunto Función de abstracción
      *
      * Un objeto válido @e rep del TDA Matriz Dispersa representa la estructura
      *
      * rep.m[<0,0,'A'>,<0,0,'B'>...<i,j,'*'>]
      *
      */
    private:
      struct tripleta{
        int fila; /**< fila */
        int col; /**< columna */
        T d; /**< dato */
      }; /**< estructura */

      Vector_Dinamico<tripleta> m; /**< vector 1d */
      T valor_defecto; /**< valor por defecto */

    public:

      /**
        *
        * @brief Constructor por defecto
        * Crea un objeto de la clase Matriz Dispersa con valor por defecto '0'
        *
        */
      Matriz_Dispersa<T>(T valor = '0');

      /**
        *
        * @brief Modifica el valor por defecto
        * @param dato es el valor por defecto
        *
        */
      void setValorDefecto(const T &dato){ valor_defecto = dato; }

      /**
        *
        * @brief Devuelve el numero de elementos del vector
        *
        */
      int size(){ return m.size(); }

      /**
        *
        * @brief Dimensiona el tamaño del vector
        * @param tam es el nuevo tamaño
        * @pre tam debe ser mayor o igual que 0
        *
        */
      void resize(int tam){ return m.Resize(tam); }

      /**
        *
        * @brief Obtiene el elemento de la posición fil,col
        * @param fil fila
        * @param col columna
        * @return Devuelve el objeto por copia
        *
        */
      T getElemento(int fil, int col);

      /**
        *
        * @brief Obtiene la menor fila
        * @return Devuelve la posicion de la menor fila
        *
        */
      int getMenor_Fila();

      /**
        *
        * @brief Obtiene la mayor fila
        * @return Devuelve la posicion de la mayor fila
        *
        */
      int getMayor_Fila();

      /**
        *
        * @brief Obtiene la menor columna
        * @return Devuelve la posicion de la menor columna
        *
        */
      int getMenor_Columna();

      /**
        *
        * @brief Obtiene la mayor columna
        * @return Devuelve la posicion de la mayor columna
        *
        */
      int getMayor_Columna();

      /**
        *
        * @brief Devuelve el valor por defecto
        *
        */
      T get_Valor_Defecto();

      /**
        *
        * @brief Obtiene el numero de casillas sin valor por defecto
        *
        */
      int Casillas_Sin_Valor_Defecto();

      /**
        *
        * @brief Obtiene el número de filas
        *
        */
      int getFilas();

      /**
        *
        * @brief Obtiene el número de columnas
        *
        */
      int getColumnas();

      /**
        *
        * @brief Coloca un elemento en la fila i y la columna j
        * @param i es la fila
        * @param j es la columna
        * @param valor Valor que introducimos
        *
        */
      void setElemento(int i, int j, T valor);

      /**
    		* @brief Sobrecarga del operador <<
    		* Imprime la matriz dispersa
    		* @param m el flujo de salida
    		* @param matriz la referencia al objeto que llama al método
    		*/
  		friend ostream & operator<<(ostream &m, Matriz_Dispersa & matriz){

          for(int i=0; i<matriz.getFilas(); i++){
            m << endl;
            for(int j=0; j<matriz.getColumnas(); j++){
              m << " | " << matriz.getElemento(i,j);
            }
          }

    			return m;
    	}
};

#include "../src/Matriz_Dispersa.cpp"
#endif
