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

template<class T>
struct tripleta{
  int fila; /**< fila */
  int col; /**< columna */
  T d; /**< dato */

  bool operator<(tripleta<T>& a){
    if(this->fila < a.fila)
    return true;
    else if(this->fila == a.fila && this->col == a.col)
    return true;
    else
    return false;
  }

  friend ostream & operator<<(ostream &os, tripleta<T>& t){
    os << t.d;
    return os;
  }

}; /**< estructura */

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

      list<tripleta<T>> m; /**< list */
      T valor_defecto; /**< valor por defecto */

    public:

      /**
        * @brief Constructor por defecto
        * @return Crea un objeto de la clase Matriz Dispersa con valor por defecto '0'
        */
      Matriz_Dispersa();

      Matriz_Dispersa(T valor);

      /**
        *
        * @brief Modifica el valor por defecto
        * @param dato es el valor por defecto
        *
        */
      void setValorDefecto(const T &dato){ valor_defecto = dato; }

      pair<bool, typename list<tripleta<T>>::iterator> posicion_indice(int i, int j);

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

      list<tripleta<T>> getMatriz();

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

      class iterator{
        private:
          typename list<tripleta<T>>::iterator it;
        public:
          iterator & operator++(){
            do{
              ++it;
            }while((*it).d == valor_defecto);
            return *this;
         }
         iterator & operator--(){
           do{
             --it;
           }while((*it).d == valor_defecto);
           return *this;
         }
         tripleta<T> &operator *(){
           return (*it);
         }
         bool operator ==(const iterator &i){
           return i.it==it;
         }
         bool operator !=(const iterator &i){
           return i.it!=it;
         }
         friend class Matriz_Dispersa;
      };

      class const_iterator {
        private:
            typename list<tripleta<T>>::const_iterator it;
        public:
            const_iterator(){}

            bool operator ==(const const_iterator i)const{
                return i.it==it;
            }

            bool operator !=(const const_iterator i)const{
                return i.it!=it;
            }
            const tripleta<T>& operator*()const{
                return *it;
            }
            const_iterator & operator ++(){
                ++it;
                return *this;
            }
            const_iterator & operator --(){
                --it;
                return *this;
            }
            friend class Matriz_Dispersa;
            friend class iterator;
      };

      /**
  		 * @brief Inicializa un iterator al comienzo de la matriz
  		 * */
  		 iterator begin(){
  			 iterator i;
  			 i.it=m.begin();
         if(*(i.it).d == valor_defecto) i++;
  			 return i;
  		 }

  		/**
  		 * @brief Inicializa un iterator al final de la matriz
  		 * */
  		 iterator end(){
         iterator i;
         i.it=m.end();
         if(*(i.it).d == valor_defecto) i--;
         return i;
  		 }

       const_iterator cbegin()const{
         const_iterator i;
         i.it=m.cbegin();
         return i;
       }
       const_iterator cend()const{
          const_iterator i;
          i.it=m.cend();
          return i;
       }
};

#include "../src/Matriz_Dispersa.cpp"
#endif
