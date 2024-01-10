// dynamic_cast
#include <iostream>
#include <exception>
using namespace std;

class A { public: int i; int x; };
class B { public: int i; };

int main () {
  A* a = new A;
  a->i = 1075;
  B* b = reinterpret_cast<B*>(a);
  std::cout << b->i << std::endl;
}
