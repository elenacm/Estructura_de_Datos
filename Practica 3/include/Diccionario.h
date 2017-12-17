/**
 * @ file : Diccionario.h
 * @brief: TDA Diccionario
 * */

#ifndef _DICCIONARIO_H
#define _DICCIONARIO_H
#include <map>
#include <iostream>
#include <string>
#include <list>
#include "Sopa_Letras.h"

using namespace std;

class Diccionario{
	private:
		multimap<string,string> datos;
		Sopa_Letras sopa;
	public:

		/**
			* @brief Constructor por defecto de la clase diccionario
			*/
		Diccionario() : datos(){}

		/**
			* @brief Consultor del multimap
			* @return datos
			*/
		multimap<string,string> getMultimap()const;

		/**
			* @brief Metodo para escoger x palabras aleatorias del diccionario
			* @return Devuelve un diccionario con las palabras-definciones elegidas
			* @pre x < diccionario.size()
			*/
		Diccionario escogePalabras(int b);

		/**
			* @brief Pone las palabras del diccionarioen la sopa de letras
			* @pre diccionario no vacio
			*/
		void ponePalabraEnSopa();

		/**
			*	@brief Borra una palabra y su definicion de la lista de palabras
			* @param palabra palabra que se va a borrar
			*/
		void Borrar(const string &palabra);

		/**
			* @brief Consultor de la sopa de letras
			* @return sopa
			*/
		Sopa_Letras getSopa(){ return sopa; }

		/**
			* @brief Método para encontrar la definicion de una palabra determinada
			* @param palabra palabra que se quiere buscar su definicion
			* @return Devuelve una lista con las distintas definicionesque pueda tener una palabra
			*/
		list<string> BuscaDef(const string &palabra) const;

		/**
			* @brief Metodo para saber el tamaño del multimap
			* @return tamaño de datos
			*/
		int size(){ return datos.size(); }

		/**
			* @brief Método para obtener las definiciones con la palabra indicada
			* @param palabra palabra que se busca en cada definicion del Diccionario
			* @return Devuelve un Diccionario con todas las definiciones que contienen esa palabra
			*/
		Diccionario ObtainPalabrasconDeficionContiene(string palabra);

		/**
			* @brief ITERDORES
			*/
		class iterator{
			private:
				typename multimap<string,string>::iterator it;
		 	public:
				iterator(){}
				iterator & operator++(){
					++it;
					return *this;
			 }
			 iterator & operator--(){
		 	 	--it;
		 		return *this;
			 }
			 pair<const string,string> &operator *(){
				 return *it;
			 }
			 bool operator ==(const iterator &i){
				 return i.it==it;
			 }
			 bool operator !=(const iterator &i){
				 return i.it!=it;
			 }
			 friend class Diccionario;
			 friend class const_iterator;
		};

		class const_iterator {
      private:
          typename multimap<string, string>::const_iterator it;
      public:
          const_iterator(){}
					const_iterator & operator ++(){
						++it;
						return *this;
					}
					const_iterator & operator --(){
						--it;
						return *this;
					}
          bool operator ==(const const_iterator i)const{
              return i.it==it;
          }
          bool operator !=(const const_iterator i)const{
              return i.it!=it;
          }
          const pair<const string, string>& operator*()const{
              return *it;
          }
          friend class Diccionario;
          friend class iterator;
    };

		/**
		 * @brief Inicializa un iterator al comienzo del diccionario
		 */
		 iterator begin(){
			 iterator i;
			 i.it=datos.begin();
			 return i;
		 }

		/**
		 * @brief Inicializa un iterator al final del diccionario
		 */
		 iterator end(){
			 iterator i;
			 i.it=datos.end();
			 return i;
		 }

		 /**
 		 * @brief Inicializa un iterator al comienzo del diccionario
 		 */
 		 const_iterator cbegin()const{
 			 const_iterator i;
 			 i.it=datos.cbegin();
 			 return i;
 		 }

 		/**
 		 * @brief Inicializa un iterator al final del diccionario
 		 */
 		 const_iterator cend(){
 			 const_iterator i;
 			 i.it=datos.cend();
 			 return i;
 		 }

		 /**
		 	* @brief operador de entrada
			*/
		 friend istream & operator>>(istream &is, Diccionario &d){
			 pair<string,string> p;

				 while(getline(is,p.first,';')){
					 getline(is,p.second);

					 d.datos.insert(p);
			 	 }
		 	  return is;
		 }

		 /**
		 	* @brief operador de salida
			*/
		 friend ostream & operator<<(ostream &os, Diccionario &d){

		 	  for(auto it = d.datos.begin(); it != d.datos.end(); ++it){
					os << it->first << " : " << it->second << endl;
				}
		 	  return os;
		 }
};

#endif
