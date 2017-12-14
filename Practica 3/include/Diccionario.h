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

using namespace std;

class Diccionario{
	private:
		multimap<string,string> datos;
	public:
		Diccionario() : datos(){}

		void Insertar(string palabra, string def);
		void Borrar(const string &palabra, const string &def);
		list<string> BuscaDef(const string &palabra) const;
		int size(){ return datos.size(); }
		unsigned int contabiliza(const string &palabra);
		void clear(){ datos.clear(); }
		Diccionario ObtainPalabrasconDeficionContiene(string palabra);


		class iterator{
			private:
				map<string,string>::iterator it;
		 	public:
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
