#include <iostream>
#include <ctime>    // Recursos para medir tiempos
#include <cstdlib>  // Para generación de números pseudoaleatorios

using namespace std;

int main(int argc, char * argv[]){
  // Lectura de parámetros
  if (argc!=2){
    cerr << "Formato " << argv[0] << " <num_elem>" << endl;
    return -1;
  }

  int tam=atoi(argv[1]);     // Tamaño del vector

  //Reserva de memoria para matrices
  int **A = new int * [tam];
  int **C = new int * [tam];
  int **B = new int * [tam];

  for(int i = 0; i < tam; i++){
    A[i] = new int[tam];
    B[i] = new int[tam];
    C[i] = new int[tam];
  }

  srandom(time(0));

  for(int i  = 0; i < tam; i++)
    for(int j = 0; j < tam; j++){
      A[i][j] = 0;
      B[i][j] = random();
      C[i][j] = random();
    }

  clock_t tini;    // Anotamos el tiempo de inicio
  tini=clock();

  int i,j, k;

  //Calculamos el producto de ambas
  for (i = 0; i < tam; i++)
    for (j = 0; j < tam; j++)
      for (k = 0; k < tam; k++)
        A[i][j] += B[i][k] * C[k][j];

  clock_t tfin;    // Anotamos el tiempo de finalización
  tfin=clock();

  // Mostramos resultados
  cout << tam << "\t" << (tfin-tini)/(double)CLOCKS_PER_SEC << endl;

  delete [] A;     // Liberamos memoria dinámica
  delete [] B;
  delete [] C;

  return 0;
}
