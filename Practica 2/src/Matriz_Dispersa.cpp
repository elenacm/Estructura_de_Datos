
//Constructor por defecto
template <class T>
Matriz_Dispersa<T>::Matriz_Dispersa(T valor){
  valor_defecto = valor;
}

//Modificador del elemento (i,j)
template <class T>
void Matriz_Dispersa<T>::setElemento(int i, int j, T valor){
  cout << "Introduciendo dato en fila " << i << " y columna " << j << endl;
  if(valor != valor_defecto){
    tripleta tri;
    tri.fila = i;
    tri.col = j;
    tri.d = valor;
    m.Insertar(tri, size()-1);
  }
  else{
    m.Borrar(i*getColumnas() + j);
  }
}

//Consultor del elemento (i,j)
template <class T>
T Matriz_Dispersa<T>::getElemento(int fil, int col){
  T dato = valor_defecto;

  for(int i=0; i<size(); i++){
    if(m[i].fila == fil && m[i].col == col)
      dato = m[i].d;
  }

  return dato;
}

//Consultor menor fila
template <class T>
int Matriz_Dispersa<T>::getMenor_Fila(){
  int menor_f = m[0].fila;
  for(int i=0; i<size(); i++){
    if(m[i].fila < menor_f)
      menor_f = m[i].fila;
  }

  return menor_f;
}

//Consultor mayor fila
template <class T>
int Matriz_Dispersa<T>::getMayor_Fila(){
  int mayor_f = m[0].fila;
  for(int i=0; i<size(); i++){
    if(m[i].fila > mayor_f)
      mayor_f = m[i].fila;
  }

  return mayor_f;
}

//Consultor menor columna
template <class T>
int Matriz_Dispersa<T>::getMenor_Columna(){
  int menor_c = m[0].col;
  for(int i=0; i<size(); i++){
    if(m[i].col < menor_c)
      menor_c = m[i].col;
  }

  return menor_c;
}

//Consultor mayor columna
template <class T>
int Matriz_Dispersa<T>::getMayor_Columna(){
  int mayor_c = m[0].col;
  for(int i=0; i<size(); i++){
    if(m[i].col < mayor_c)
      mayor_c = m[i].col;
  }

  return mayor_c;
}

//Consultor Valor por defecto
template <class T>
T Matriz_Dispersa<T>::get_Valor_Defecto(){
  return valor_defecto;
}

//Consultor casillas sin valor por defecto
template <class T>
int Matriz_Dispersa<T>::Casillas_Sin_Valor_Defecto(){
  int casillas = 0;

  for(int i=0; i<size(); i++){
    for(int j=0; j<size(); j++){
      if(getElemento(i, j) != get_Valor_Defecto())
        casillas++;
    }
  }

  return casillas;
}

//Consultor filas de la matriz
template <class T>
int Matriz_Dispersa<T>::getFilas(){
  return (getMayor_Fila() - getMenor_Fila());
}

//Consultor columnas de la matriz
template <class T>
int Matriz_Dispersa<T>::getColumnas(){
  return (getMayor_Columna() - getMenor_Columna());
}
