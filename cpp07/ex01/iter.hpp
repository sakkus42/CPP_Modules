#include <iostream>

template<typename T, typename T2>
void iter(T* arr, std::size_t lenght, void(*f)(T2)) {
	for (std::size_t i = 0; i < lenght; ++i) {
		f(arr[i]);
	}
}