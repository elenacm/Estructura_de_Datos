#ifndef __SOBRECARGAS__H
#define __SOBRECARGAS__H
#include <iostream>
#include <set>
#include <map>
using namespace std;

istream& operator>>(istream& is, pair<set<string>,int>& mypair);

istream& operator>>(istream& is, map<int,string>& mymap);

ostream& operator<<(ostream& out, pair<set<string>,int>& mypair);

ostream& operator<<(ostream& os, set<string>& myset);

#endif
