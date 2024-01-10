#include "iter.hpp"
#include <cstdlib>

template <typename T>
void output(T x) {
    std::cout << x << std::endl;
}

void changeV(std::string& str) {
    str = str + ".2";
}

void takeEvenNumber(int& x) {
    x % 2 ? x = 0 : x;
};

class A {
    public:
        int price;
        std::string moneySign;
        A() { price = 0; moneySign = "$"; }
        A(int price) { this->price = price; moneySign = "$"; }
};


std::ostream& operator<<(std::ostream& os, A const& src){
    os << "Product price = " << src.price << src.moneySign;
    return (os);
}

void changeTrMoney(A& obj) {
    obj.price *= 29;
    obj.moneySign = "₺";
}


int main() {

    int x[] = {1, 2, 3, 4, 5};
    ::iter(x, 5, output);
    ::iter(x, 5, takeEvenNumber);
    ::iter(x, 5, output);

    std::string array[] = {"v1", "v2", "v3", "v4"};
    ::iter(array, 4, output);
    ::iter(array, 4, changeV);
    ::iter(array, 4, output);

    A prdctPrices[] = { A(123), A(100), A(45) };
    ::iter(prdctPrices, 3, output);
    ::iter(prdctPrices, 3, changeTrMoney);
    ::iter(prdctPrices, 3, output);
}