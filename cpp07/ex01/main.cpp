#include "iter.hpp"
#include <cstdlib>

template <typename T>
void output(T x) {
    std::cout << x << std::endl;
}




int main() {

    int x[] = {1, 2, 3, 4, 5};
    ::iter(x, 5, output);

    std::string array[] = {"v1", "v2", "v3", "v4"};
    ::iter(array, 4, output);


}