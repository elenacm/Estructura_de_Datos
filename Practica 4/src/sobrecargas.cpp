#include "sobrecargas.h"
#include <iostream>

using namespace std;

istream& eliminarEspacios(istream& is){
  while(is.eof()){
    if(isspace(is.peek()) || is.peek() == '\n')
      is.get();
  }

  return is;
}

istream& operator>>(istream& is, pair<set<string>,int>& mypair){
  int n;
  is >> n;

  eliminarEspacios(is);

  char palabra[100];
  for(int i = 0; i < n; i++){
    is.getline(palabra, 100, ',');
    mypair.first.insert(palabra);
  }

  is >> mypair.second;

  return is;
}

ostream& operator<<(ostream& out, pair<set<string>,int>& mypair){
  set<string>::const_iterator it_set;

  out << mypair.second;
  out << "n";
  out << mypair.first.size() << " ";
  for(it_set = mypair.first.begin(); it_set != mypair.first.end(); ++it_set){
    out << (*it_set) << flush;
    out << ",";
  }

  return out;
}
