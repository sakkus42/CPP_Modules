#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

typedef std::vector<int> vInt;

class Span {
    private:
        vInt                numbers;
        unsigned int        size;

        class notEnoughElements : public std::exception {
            public: const char* what() const throw() { return "not enough elements"; }
        };

        class outOfRange : public std::exception {
            public: const char* what() const throw() { return "index error"; }
        };
    public:
        Span(unsigned int size);


        void    addNumber(int i);
        void    addNumber(vInt::iterator itBegin, vInt::iterator itEnd);
        int     shortestSpan();
        int     longestSpan();
        vInt const& getNumbers() const;
};

std::ostream& operator<<(std::ostream& os, Span const& span);