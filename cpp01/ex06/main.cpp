#include "Harl.hpp"

int main(int ac, char *arv[]){
    if (ac != 2){
        std::cout << "Missing Argument" << std::endl;
        return (1);
    }
    Harl harl;
    harl.complain(arv[1]);
    return (0);
}