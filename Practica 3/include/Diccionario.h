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
		Diccionario() : datos(){}
		multimap<string,string> getMultimap()const;
		Diccionario escogePalabras(int b);
		void ponePalabraEnSopa();
		void Borrar(const string &palabra);
		Sopa_Letras getSopa();
		list<string> BuscaDef(const string &palabra) const;
		int size(){ return datos.size(); }
		unsigned int contabiliza(const string &palabra);
		void clear(){ datos.clear(); }
		Diccionario ObtainPalabrasconDeficionContiene(string palabra);


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
		 * */
		 iterator begin(){
			 iterator i;
			 i.it=datos.begin();
			 return i;
		 }

		/**
		 * @brief Inicializa un iterator al final del diccionario
		 * */
		 iterator end(){
			 iterator i;
			 i.it=datos.end();
			 return i;
		 }

		 /**
 		 * @brief Inicializa un iterator al comienzo del diccionario
 		 * */
 		 const_iterator cbegin()const{
 			 const_iterator i;
 			 i.it=datos.cbegin();
 			 return i;
 		 }

 		/**
 		 * @brief Inicializa un iterator al final del diccionario
 		 * */
 		 const_iterator cend(){
 			 const_iterator i;
 			 i.it=datos.cend();
 			 return i;
 		 }

		 friend istream & operator>>(istream &is, Diccionario &d){
			 pair<string,string> p;

				 while(getline(is,p.first,';')){
					 getline(is,p.second);

					 d.datos.insert(p);
			 	 }
		 	  return is;
		 }

		 friend ostream & operator<<(ostream &os, Diccionario &d){

		 	  for(auto it = d.datos.begin(); it != d.datos.end(); ++it){
					os << it->first << " : " << it->second << endl;
				}
		 	  return os;
		 }
};

#endif
