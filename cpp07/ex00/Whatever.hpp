#include <iostream>

template <typename T> void swap(T& x, T& y) {
    T tmp;
    tmp = y;
    y = x;
    x = tmp;
}

template <typename T> T min(T& x, T& y)
{ return x < y ? x : y; }

template <typename T> T max(T& x, T& y)
{ return x > y ? x : y; }



