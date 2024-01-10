#include "Array.hpp"

template <typename T>
void iter (T& array, void(*f)(T), int index = 0) {
        f(array[index]);
        iter(array, f, index + 1);
}


template <typename T>
void output(T any) {
    std::cout << 1 << std::endl;
}

int main() {
    Array<int> Int(25);
    iter(Int, output);
}