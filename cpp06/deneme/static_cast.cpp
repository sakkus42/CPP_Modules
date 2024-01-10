// dynamic_cast
#include <iostream>
#include <exception>
using namespace std;

class CBase { virtual void dummy() {} };
class CDerived: public CBase { int a; };

int main () {
  class CBase {};
  class CDerived: public CBase {};
  CBase * a = new CBase;
  CDerived * b = static_cast<CDerived*>(a);
}
