#include "PmergeMe.hpp"

int main(int ac, char** arv) {
    if (ac == 1) {
        std::cout << "Error: Invalid argument";
        return 0;
    }
    try {
        PmergeMe pm(ac - 1, arv + 1);
    } catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }
    
}