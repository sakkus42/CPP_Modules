#include "RPN.hpp"

RPN::RPN() {};
RPN::RPN(RPN const& rpn) {
    if (this != &rpn) *this = rpn;
};
RPN& RPN::operator=(RPN const& rpn) {
    if (this != &rpn) this->stack = rpn.stack; 
    return *this;
};
RPN::~RPN() {};

RPN::RPN(std::string const& arg) {
    std::stringstream argStream(arg);
    std::string letter;
    int nbr;
    while (std::getline(argStream, letter, ' ')) {
        std::stringstream ss(letter);
        if (letter == " ")
            continue;
        if (isSign(letter)) {
            if (stack.size() < 2)
                throw std::runtime_error("Error");
            int x, y,res;
            y = stack.top(); stack.pop();
            x = stack.top(); stack.pop();
            res = calc(x, y, letter[0]);
            stack.push(res);
        } else {
            ss >> nbr;
            stack.push(nbr);
        }
    }
    if (stack.size() != 1)
        throw std::runtime_error("Error");
    std::cout << stack.top() << std::endl;
};

int RPN::calc(int x, int y, char c) {
    switch (c) {
        case '+':
            return x+y;
        case '-':
            return x-y;
        case '*':
            return x*y;
        case '/':
            return x/y;
    }
    return 0;
}

bool RPN::isSign(std::string letter) {
    std::string sign[4] = {"-", "+", "*", "/"};
    for (size_t i = 0; i < 4; i++)
        if (letter == sign[i])
            return true;
    return false;
}