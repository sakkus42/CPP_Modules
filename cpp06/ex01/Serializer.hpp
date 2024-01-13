#include <iostream>

struct Data {
    int value;
    Data* both;
};

class Serializer
{
    private:
    public:
        Serializer();
        Serializer(const Serializer& other);
        ~Serializer();
        Serializer& operator=(const Serializer& other);
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};
