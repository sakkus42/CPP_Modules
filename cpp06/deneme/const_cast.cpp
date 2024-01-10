// dynamic_cast
#include <iostream>
#include <exception>
using namespace std;

void change(std::string const& str){
  std::string& s = const_cast<std::string&>(str);
  s[0] = 'i';
}

unsigned long long fibonacci(int n) {
    return (n <= 1) ? n : fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
     unsigned long long result = fibonacci(20);
    std::cout << "Fibonacci(40) = " << result << std::endl;
    return 0;
}

