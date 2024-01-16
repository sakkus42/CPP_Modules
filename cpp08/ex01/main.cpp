#include "span.hpp"

int main() {
    {
        std::cout << "pdf MAIN" << std::endl;
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }

    {
        std::cout << std::endl << "addnumber Machine" << std::endl;
        Span sp(5);
        vInt v1(2, 2);
        vInt v4(2, 4);
        sp.addNumber(1);
        sp.addNumber(v1.begin(), v1.end());
        sp.addNumber(v4.begin(), v4.end());
        std::cout << sp.longestSpan() << std::endl;
        std::cout << sp.shortestSpan() << std::endl;
        std:: cout << "vector: " << sp << std::endl;
    }

    {
        std::cout << std::endl << "Error Testing" << std::endl;
        try{
            Span sp(0);
            sp.addNumber(1);
        }catch(const std::exception& e){
            std::cerr << e.what() << '\n';
        }
        try{
            Span sp(2);
            sp.shortestSpan();
        }catch(const std::exception& e){
            std::cerr << e.what() << '\n';
        }
        try{
            Span sp(2);
            sp.longestSpan();
        }catch(const std::exception& e){
            std::cerr << e.what() << '\n';
        }
        try{
            Span sp(5);
            vInt v1(10, 2);
            sp.addNumber(v1.begin(), v1.end());
        }catch(const std::exception& e){
            std::cerr << e.what() << '\n';
        }
    }
}