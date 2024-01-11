#include "ScalarConverter.hpp"


int main(int ac, char *arv[]) {
    if (ac == 2){
        ScalarConverter::convert(arv[1]);
    } else {
        std::cout << "Arguments Invalid" << std::endl;
    }
	char c = 'a';
	int* pC = new int();
	pC = (int*)&(c);
	int* pC1 = new int();
	pC1 = static_cast<int*>(&c);
	std::cout << *pC << std::endl;
	// int* ppC = static_cast<int*>(&c);

}