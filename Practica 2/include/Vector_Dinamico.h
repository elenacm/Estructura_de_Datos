#ifndef _VECTORDINAMICO_H
#define _VECTORDINAMICO_H

#include <iostream>

using namespace std;
/**
  * @brief T.D.A. Vector_Dinamico
  *
  * Una instancia @e c del tipo de datos abstracto @c Vector Dinámico es una
  * suscesión de elementos almacenados y accesibles en memoria.
  * Se representa así:
  *
  * datos[n] donde n > 0
  *
  * @author Elena Cantero Molina
  * @date Noviembre 2017
  *
  */

template <class T>
class Vector_Dinamico{
private:
  /**
    * @page repConjunto Rep del TDA Vector Dinamico
    *
    * @section invConjunto Invariante de la representación
    *
    * El invariante es \e rep.n>=0
    *
    * @section faConjunto Función de Abstracción
    *
    * Un objeto válido @e rep del TDA Vector Dinamico representa a la estructura
    *
    * rep.datos[n]
    *
    */

  T* datos; /**< estructura */
  int n; /**< Cantidad de memoria reservada */
  int reservados; /**< Cantidad de elementos en el vector */

  /**
    * @brief Copia un vector en otro
    * @param v vector que se desea copiar
    *
    */
  void Copiar(const Vector_Dinamico<T> &v);

  /**
    * @brief Destruye el vector
    *
    */
  void Liberar();

public:
  /**
    *
    * @brief Constructor por defecto
    * @param tam tamaño a reservar del vector
    * @pre tam debe ser mayor que cero
    *
    */
  Vector_Dinamico<T>(int tam = 0);

  /**
    *
    * @brief Constructor de copia
    * @param original es el objeto a partir del cual se crea el nuevo
    * @return Crea una nueva instancia
    *
    */
  Vector_Dinamico<T>(const Vector_Dinamico<T> &original);

  /**
    *
    * @brief Destructor que libera memoria
    *
    */
  ~Vector_Dinamico<T>();

  /**
    *
    * @brief Devuelve el tamaño del vector
    *
    */
  int size() const;

  /**
    *
    * @brief Redimensiona el tamaño del vector
    * @param nuevot es el nuevo tamaño
    * @pre nuevot debe ser mayor o igual que 0
    *
    */
  void Resize(int nuevot);

  /**
    *
    * @brief Devuelve la cantidad de memoria reservada
    *
    */
  const int getReservados() const {return reservados;}

  /**
    *
    * @brief Sobrecarga del operador []
    * @param i es el indice del dato que se quiere obtener
    * @return Devuelve el objeto por referencia
    * @pre i debe ser mayor o igual que cero
    *
    */
  T &operator[](int i);

  /**
    *
    * @brief Sobrecarga del operador []
    * @param i es el indice del dato que se quiere obtener
    * @return Devuelve una constante por referencia del objeto
    * @pre i debe ser mayor o igual que cero
    *
    */
  const T &operator[](int i) const;

  /**
    *
    * @brief Sobrecarga del operador =
    * @param orig es el objeto a partir del cual se va a crear el nuevo
    * @return Asigna el contenido de orig a otro vector
    *
    */
  Vector_Dinamico<T> &operator=(const Vector_Dinamico<T> &orig);

  /**
    *
    * @brief Coloca un elemento en la posición pos
    * @param pos es la posición en la que se va a colocar el elemento
    * @param dato es el dato que se va a insertar
    * @pre pos debe ser mayor o igual que cero
    *
    */
  void Insertar(const T &dato, int pos);

  /**
    *
    * @brief Borra un elemento de la posicion pos
    * @param pos posicion que se va a eliminar
    * @pre pos debe ser mayor o igual que cero
    *
    */
  void Borrar(int pos);

  /**
    *
    * @brief Busca un elemento en el vector
    * @param busco es elemento que se quiere encontrar
    * @return posicion en la que se encuentra elemento
    *
    */
  int Buscar(T busco);
};

#include "../src/Vector_Dinamico.cpp"
#endif
