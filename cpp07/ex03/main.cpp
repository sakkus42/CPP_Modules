#include "Array.hpp"

template <typename T, typename Func>
void iter (T& array, Func f, int index = 0) {
	if (index < (int)array.size()){
		f(array[index]);
		iter(array, f, index + 1);
	}
}

template <typename T>
void output(T any) {
    std::cout << any << std::endl;
}

template <typename T>
void fillArrayInt(T& any) {
	any = 1;
}

int main() {
{
}