#ifndef __SOBRECARGAS__H
#define __SOBRECARGAS__H
#include <iostream>
#include <set>
using namespace std;

istream& eliminarEspacios(istream& is);

istream& operator>>(istream& is, pair<set<string>,int>& mypair);

ostream& operator<<(ostream& out, pair<set<string>,int>& mypair);

ostream& operator<<(ostream& os, set<string>& myset);

#endif
