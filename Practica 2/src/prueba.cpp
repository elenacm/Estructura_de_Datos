
//Este fichero te permite probar el modulo matriz dispersa.

#include "./Matriz_Dispersa.h"
#include <iostream>
#include <cstring>

using namespace std;
int main(){

 Matriz_Dispersa<char> P('0');
 int r,c;
 r=2;c=2;
 //La Ponemos horizontal
 const char * cad="hola";
 for (unsigned int i=0;i<strlen(cad);i++,c++)
     P.setElemento(r,c,cad[i]);
 r=2;c=2;

 for (unsigned int i=0;i<strlen(cad);i++,r++)
     P.setElemento(r,c,cad[i]);
 cout << P << endl;

 cout << P.get_Valor_Defecto() << endl;

 P.setValorDefecto('X');
 cout << "valor por defecto " << P.get_Valor_Defecto() << endl;
 cout << "get min col " << P.getMenor_Columna() << endl;
 cout << "get max col " << P.getMayor_Columna() << endl;
 cout << "get min fila " << P.getMenor_Fila() << endl;
 cout << "get max fila " << P.getMayor_Fila() << endl;
 cout << "tamaño " << P.size() << endl;
 P.setElemento(-1,15,'U');
 cout << "get min col " << P.getMenor_Columna() << endl;
 cout << "get max col " << P.getMayor_Columna() << endl;
 cout << "get min fila " << P.getMenor_Fila() << endl;
 cout << "get max fila " << P.getMayor_Fila() << endl;
 cout << "tamaño " << P.size() << endl;
 cout << "num filas " << P.getFilas() << endl;
 cout << "num columnas " << P.getColumnas() << endl;
 cout << "get at -1,15: " << P.getElemento(-1,15) << endl;
 cout << "get at -1,15: " << P.getElemento(-1,15) << endl;
 cout << "get at 2,2: " << P.getElemento(2,2) << endl;
 cout << "get at 10,10: " << P.getElemento(10,10) << endl;
}
