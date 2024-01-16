#include "easyfind.hpp"

int main() {
    std::vector<int> vInt;
    vInt.push_back(1);
    vInt.push_back(2);
    vInt.push_back(3);
    vInt.push_back(4);
    try{
        easyfind(vInt, 4);
        easyfind(vInt, 10);
    }catch(const std::exception& e){
        std::cerr << e.what() << std::endl;
    }
}