#include "Harl.hpp"

int main(){
    Harl harl;
    std::string input;

    do
    {
        std::cout << "Enter a Level(debug/info/warning/error): ";
        std::cin >> input;
        if (!std::cin.good()){
            std::cout << std::endl;
            break;
        }
        harl.complain(input);
    } while (input != "exit");
    return (0);
}