#include <iostream>

template <typename T>

class Array{
    private:
        T* value;
        size_t len;
    public:
        Array() {
            len = 0;
            this->value = new T();
        };

        ~Array() {
            delete [] this->value;
        };

        Array(unsigned int n) {
            len = n;
            this->value = new T[len];
        }

        Array(Array const& other) {
            if (this != &other) {
                *this = other;
            }
            return;
        }

        Array& operator=(Array const& other) {
            if (this == &other) return *this;
            this->len = other.size();
            this->value = new T[this->len];
            for (size_t i = 0; i < this->len; i++) this->value[i] = other.value[i];
            return *this;
        }

        T& operator[](size_t i) { 
            if (i >= len) throw std::exception();
            return (this->value[i]);
        }

        size_t size() const { return this->len; }
};
