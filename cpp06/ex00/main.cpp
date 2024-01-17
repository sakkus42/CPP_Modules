#include "ScalarConverter.hpp"


int main(int ac, char *arv[]) {
    if (ac == 2){
        ScalarConverter::convert(arv[1]);
    } else {
          std::cout << "Arguments Invalid" << std::endl;
    }
	
}
