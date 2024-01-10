#include <iostream>

template <typename T> 

void iter (T* array, size_t len, void(*f)(T&)) {
    if (len != 0) {
        f(*array);
        iter(array + 1, len - 1, f);
    }
}