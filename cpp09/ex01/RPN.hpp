#include <iostream>
#include <map>
#include <stack>
#include <sstream>

class RPN {
    private:
        std::stack<int> stack;
        
        int     calc(int x, int y, char c);
        bool    isSign(std::string letter);
    public:
        RPN();
        RPN(std::string const& arg);
        RPN(RPN const& rpn);
        RPN& operator=(RPN const& rpn);
        ~RPN();
};
