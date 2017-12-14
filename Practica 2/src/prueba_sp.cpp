#include "./Matriz_Dispersa.h"
#include <cstring>
#include <fstream>
#include "./Sopa_Letras.h"
#include <iostream>

using namespace std;

int main(int argc, char * argv[]){

    if (argc!=2){
      cout<<"Dime el nombre del fichero con las palabras de la sopa de letras"<<endl;
      return 0;
    }
    ifstream f(argv[1]);
    if (!f){
	      cout<<"No puedo abrir "<<argv[1]<<endl;
	      return 0;
    }

    Sopa_Letras Sl;
    f >> Sl;//Leemos las palabras y construimos la sopa de letras
    //El usuario ahora tiene que ir descubriendo las palabras
    //en la sopa de letras
    while (Sl.Numero_Palabras()!=0){
       cout<<Sl<<endl;
       cout<<"Dime una palabra: ";
       string word;
       cin>>word;
       cout<<"Dime la fila :";
       int row;
       cin>>row;
       cout<<"Dime la columna :";
       int col;
       cin>>col;

       cout<<"Direccion Arriba (vu), Abajo (vd), Izquierda (hl) , Derecha (hr), Diagonal abajo derecha (ddr),Diagonal abajo izquierda (ddl) :";
       string direccion;
       cin>>direccion;
       if (!Sl.Esta_Palabra(word,row,col,direccion)){//Esta?
	 cout<<"La palabra "<<word << " no esta"<<endl;
       }
       else{
	 //La pone en negrita. Ademas la pone dentro de la lista de palabras descubiertas.
	  Sl.Poner_Palabra(word,row,col,direccion);
       }
    }
    cout<<Sl<<endl;

}
