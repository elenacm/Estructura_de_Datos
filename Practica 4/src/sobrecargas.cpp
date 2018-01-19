#include "sobrecargas.h"
#include <iostream>

using namespace std;

istream& operator>>(istream& is, pair<set<string>,int>& mypair){
  int n;
  is >> n;

  is.ignore();

  char palabra[100];
  for(int i = 0; i < n; i++){
    is.getline(palabra, 100, ',');
    mypair.first.insert(palabra);
  }

  is >> mypair.second;

  return is;
}

istream& operator>>(istream& is, map<int,string>& mymap){
  string def;
  int numero;

  while(is >> numero){
    is.ignore();
    getline(is,def,  '\n');
    mymap.insert(pair<int,string>(numero,def));
  }

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

ostream& operator<<(ostream& os, set<string>& myset){
  set<string>::const_iterator it;

  for(it = myset.cbegin(); it != myset.cend(); ++it){
    os << *it << std::endl;
  }

  return os;
}
