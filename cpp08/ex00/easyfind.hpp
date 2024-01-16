#include <iostream>
#include <vector>
#include <algorithm>

class occurrenceIstFound : public std::exception {
    public:
        const char* what() const throw(){
            return "no occurrence is found";
        }
};

template<typename T>
void easyfind(T& container, int val) {
    if (std::find(container.begin(), container.end(), val) != container.end()) {
        std::cout << "Value: " << val << " founded in container!" << std::endl;
    } else {
        throw occurrenceIstFound();
    }
}