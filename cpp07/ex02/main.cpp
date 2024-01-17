#include "Array.hpp"
#include <unistd.h>



template<typename T>
void printArray(T const& value) 
{ std::cout << value << std::endl; }

template<typename T1, typename T2>
void each(T1& array, size_t len, void(*f)(T2&)) {
    for (size_t i = 0; i < len; i++)
        f(array[i]);
}

void fillInt(int& x) {
    static int i;
    x = i++;
}

void fillStr(std::string& str) {
    static int i = 1;
    str = std::to_string(i++) + ".Hello Template";
}

int main() {
    Array<int> Int(4);
    each(Int, Int.size(), printArray<int>);
    each(Int, Int.size(), fillInt);
    each(Int, Int.size(), printArray<int>);
    std::cout << std::endl;
    
    Array<std::string> string(4);
    each(string, string.size(), printArray<std::string>);
    each(string, string.size(), fillStr);
    each(string, string.size(), printArray<std::string>);

    std::cout << std::endl 
    << "Deep Copy Test" 
    << std::endl << std::endl;
    Array<std::string> cpyStr = string;
    each(string, string.size(), printArray<std::string>);
    cpyStr[2] = "Bye Bye Template";
    std::cout << "cpyStr[2]: " << cpyStr[2] << std::endl;
    std::cout << "string[2]: " << string[2] << std::endl;

    std::cout << std::endl 
    << "Test Error" 
    << std::endl << std::endl;
    try{
        cpyStr[-1];
    } catch(const std::exception& e){ 
        std::cerr << e.what() << '\n';
    }
        
    
}