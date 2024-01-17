#include "Whatever.hpp"

class A{
    public:
        std::string str;
        A() {};
        A(std::string str) { this->str = str; }
};



int main( void ) {
    int a = 2;
    int b = 3;
    ::swap( a, b );
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
    std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
    std::string c = "chaine1";
    std::string d = "chaine2";
    ::swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
    std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

    A str1 = std::string("süleyman");
    A str2 = std::string("akkuş");
    ::swap(str1, str2);
    std::cout << "str1 = " << str1.str << std::endl <<"str2 = " << str2.str << std::endl;
    return 0;
}