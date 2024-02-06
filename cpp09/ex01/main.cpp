#include "RPN.hpp"

int main (int ac, char** arv) {
    if (ac != 2) {
        std::cout << "Error: Invalid Argument" << std::endl;
        return 0;
    }
    try{
        RPN rpn(arv[1]);
    } catch(const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    
}