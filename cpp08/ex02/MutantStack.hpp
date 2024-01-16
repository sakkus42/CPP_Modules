#include <iostream>
#include <iterator>
#include <stack>
#include <list>

template<typename T>

class MutantStack : public std::stack<T> {
    public:
        typedef typename MutantStack<T>::container_type::iterator iterator;
        MutantStack() {
            std::cout << "MutantStack crt" << std::endl;
        }

        MutantStack& operator=(const MutantStack& value){
			if (this != &value)
				this->c = value.c;
			return *this;
		}
        
        iterator begin() {
            return(this->c.begin());
        }

        iterator end() {
            return(this->c.end());
        }
};