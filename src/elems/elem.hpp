#ifndef ELEM
#define ELEM

#include <iostream>
using namespace std;

class Elem{
  private:
    string symb;
  public:
    Elem(const string);
    friend ostream& operator<<(ostream& , const Elem&);
};

#endif
