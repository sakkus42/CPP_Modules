#include "BitcoinExchange.hpp"

int main(int ac, char** arv) {
    if (ac != 2) {
        std::cout << "Error: could not open file." << std::endl;
        return 0;
    }
    try {
        BitcoinExchange btc(arv[1]);
    } catch(const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    
}