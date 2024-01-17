#include "C.hpp"
#include <iostream>

Base* generate(void) {
    srand((unsigned) time(NULL));
    int rand[] = {std::rand() % 10, std::rand() % 10, std::rand() % 10};

    if (rand[0] > rand[1] && rand[0] > rand[2]){
        return new A;
    } else if (rand[1] > rand[0] && rand[1] > rand[2]) {
        return new B;
    } else {
        return new C;
    }

}

void identify(Base* p) {
    A* idA = dynamic_cast<A*>(p);
    B* idB = dynamic_cast<B*>(p);
    C* idC = dynamic_cast<C*>(p);
    std::cout << "pointer type is ";
    if (idA) 
        std::cout << "A" << std::endl;
    else if (idB) 
        std::cout << "B" << std::endl;
    else if (idC)
        std::cout << "C" << std::endl;
    else 
        std::cout << "unknow" << std::endl;
    
}

void identify(Base& p) {
    std::cout << "reference type is ";
    try{
        (void)dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        return;
    }catch(std::bad_cast&) {}

    try{
        (void)dynamic_cast<B&>(p);
        std::cout << "B" << std::endl; 
        return;
    }catch(std::bad_cast&) {}

    try{
        (void)dynamic_cast<C&>(p);
        std::cout << "C" << std::endl; 
        return;
    }catch(std::bad_cast&) {}
    
    std::cout << "unknow" << std::endl;
}


class D : public Base
{};

int main() {
    
    {
        Base* whoIs = generate();
        identify(whoIs);
        identify(*whoIs);
        delete whoIs;
    }
    {
        Base* whoIs = new D;
        identify(whoIs);
        identify(*whoIs);
        delete whoIs;
    }
}