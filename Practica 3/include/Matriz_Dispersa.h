/**
  * @file Matriz_Dispersa.h
  * @brief Fichero cabecera del TDA Matriz Dispersa
  *
  */

#ifndef _MATRIZ_DISPERSA_H
#define _MATRIZ_DISPERSA_H

#include <iostream>
#include <list>
#include <string>
#include <limits.h>

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
        bool acertada = false; /**< palabra acertada */
      }; /**< estructura */

      list<tripleta> m; /**< list */
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
      *   @brief borrar
      *   @fila  fila del elemento de la matriz que queremos borrar
      *   @col   columna del elemento de la matriz que queremos borrar
      *   metodo que elimina un elemento de la matriz dandole una posicion de columna y de fila
      */
      void borrar(int fila,int col);

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
      void append(int i, int j, T valor);

      /**
        *
        */
      bool estaAcertada(int fila, int columna);

      /**
        *
        */
      void ponerAcertada(int fila, int columna);

      /**
    		* @brief Sobrecarga del operador <<
    		* Imprime la matriz dispersa
    		* @param m el flujo de salida
    		* @param matriz la referencia al objeto que llama al método
    		*/
  		friend ostream & operator<<(ostream &m, Matriz_Dispersa<T> & matriz){

        m << "  " << flush;
          for(int i = matriz.getMenor_Columna(); i <= matriz.getMayor_Columna(); i++){
            m << i << " ";
          }

          m << endl;

          for(int i = matriz.getMenor_Fila(); i <= matriz.getMayor_Fila(); i++){
            m << i << " " << flush;

            for(int j = matriz.getMenor_Columna(); j <= matriz.getMayor_Columna(); j++){
              if(matriz.getElemento(i,j) != matriz.get_Valor_Defecto()){
                m << (char)(toupper(matriz.getElemento(i,j))) << " " << flush;
              }
              else{
                char aleatorio = 65 + rand() % (90-65);
                m << aleatorio << " " << flush;
              }
            }

            m << endl;
          }

    			return m;
    	}

      class iteratorNoDefecto{
        private:
          typename list<tripleta>::iterator it;
        public:
          iteratorNoDefecto & operator++(){
            do{
              ++it;
            }while((*it).d == valor_defecto);
            return *this;
         }
         iteratorNoDefecto & operator--(){
           do{
             --it;
           }while((*it).d == valor_defecto);
           return *this;
         }
         tripleta &operator *(){
           return (*it);
         }
         bool operator ==(const iteratorNoDefecto &i){
           return i.it==it;
         }
         bool operator !=(const iteratorNoDefecto &i){
           return i.it!=it;
         }
         friend class Matriz_Dispersa;
      };

      /**
  		 * @brief Inicializa un iterator al comienzo de la matriz
  		 * */
  		 iteratorNoDefecto begin(){
  			 iteratorNoDefecto i;
  			 i.it=m.begin();
         if(*(i.it).d == valor_defecto) i++;
  			 return i;
  		 }

  		/**
  		 * @brief Inicializa un iterator al final de la matriz
  		 * */
  		 iteratorNoDefecto end(){
         iteratorNoDefecto i;
         i.it=m.end();
         if(*(i.it).d == valor_defecto) i--;
         return i;
  		 }
};

#include "../src/Matriz_Dispersa.cpp"
#endif
