#include <iostream>

class IntTry{
    private:
        int _n;
    public:
        IntTry(int n) : _n(n) {};
};

int main(){
    std::string str = "HI THIS IS BRAIN";
    std::string *stringPtr = &str;
    std::string &stringRef = str;
    
    std::cout << "ADDRESS=>" << std::endl; 
    std::cout << "str:      " << &str << std::endl;
    std::cout << "strPtr:   " << stringPtr << std::endl;
    std::cout << "strRef:   " << &stringRef << std::endl;

    std::cout << "VALUES=>" << std::endl; 
    std::cout << "str:      " << str << std::endl;
    std::cout << "strPtr:   " << *stringPtr << std::endl;
    std::cout << "strRef:   " << stringRef << std::endl;
}