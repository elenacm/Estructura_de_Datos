/**
  * @file Vector_Dinamico.cpp
  * @brief Implementación del TDA Vector_Dinamico
  *
  */

/*_________________________________________________*/

template <class T>
void Vector_Dinamico<T>::Resize(int nuevotam){
  Vector_Dinamico<T> aux(*this);
  delete[] datos;
  reservados = nuevotam;
  n = aux.n;
  datos = new T[reservados];
  for(int i = 0;i<n;i++)
    datos[i] = aux.datos[i];
  }

/*_________________________________________________*/

template <class T>
Vector_Dinamico<T>::Vector_Dinamico(int tam){
  if(tam != 0){
    datos = new T[tam];
    reservados = tam;
    n = 0;
  }
  else{
    reservados = 0;
    n = 0;
    datos = 0;
  }
}

/*_________________________________________________*/

template <class T>
Vector_Dinamico<T>::Vector_Dinamico(const Vector_Dinamico<T> &original){
  reservados = original.reservados;
  n = original.n;

  if(reservados > 0)
    datos = new T[reservados];
  else
    datos = 0;

  for(int i=0; i<n; i++)
    datos[i] = original.datos[i];
}

/*_________________________________________________*/

template <class T>
Vector_Dinamico<T>::~Vector_Dinamico(){
  if(datos != 0)
    delete[] datos;
}

/*__________________________________________*/

template <class T>
int Vector_Dinamico<T>::size() const{
  return n;
}

/*_________________________________________________*/

template <class T>
T& Vector_Dinamico<T>::operator[](int i){
  return datos[i];
}

/*_________________________________________________*/

template <class T>
const T& Vector_Dinamico<T>::operator[](int i) const{
  return datos[i];
}

/*_________________________________________*/

template <class T>
Vector_Dinamico<T>& Vector_Dinamico<T>::operator=(const Vector_Dinamico<T> &orig){
  if(this != &orig){
    if(datos != 0)
      delete[] datos;
    reservados = orig.reservados;
    n = orig.n;
    if(orig.datos != 0){
      datos = new T[reservados];
    }
    for(int i=0; i<n; i++)
      datos[i] = orig.datos[i];
  }
  return *this;
}

/*_________________________________________________*/

template <class T>
void Vector_Dinamico<T>::Insertar(const T &dato, int pos){
  if(n >= reservados){
    Resize(2*reservados);
  }
  for(int i=n; i>pos; i++)
    datos[i] = datos[i-1];

  datos[pos] = dato;
  n++;
}

/*_________________________________________________*/

template <class T>
void Vector_Dinamico<T>::Borrar(int pos){
  for(int i=pos; i<n-1; i++)
    datos[i] = datos[i+1];

  n--;
  if(n < reservados)
    Resize(reservados/2);
}

/*_________________________________________*/

template <class T>
int Vector_Dinamico<T>::Buscar(T busco){
  for(int i=0;i<n;i++){
    if(datos[i] == busco){
      return i;
    }
  }
  return -1;
}
