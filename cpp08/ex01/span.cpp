#include "span.hpp"

Span::Span(unsigned int size){
    this->size = size;
}

void Span::addNumber(int i) {
    if (this->numbers.size() < this->size) {
        numbers.push_back(i);
    } else {
        throw outOfRange(); // out of range
    }
}

int     Span::shortestSpan() {
    if (this->numbers.size() < 2) {
        throw notEnoughElements(); // need more number
    }
    int minDistance = INT_MAX;
    vInt cpy = numbers;
    std::sort(cpy.begin(), cpy.end());
    for (size_t i = 1; i < cpy.size(); i++){
        int distance = std::abs(cpy[i] - cpy[i - 1]);
        minDistance = distance < minDistance ? distance : minDistance; 
    }
    
    return minDistance;
}

int     Span::longestSpan() {
    if (this->numbers.size() < 2) {
        throw notEnoughElements();
    }
    vInt::iterator itMin;
    vInt::iterator itMax;
    itMin = std::min_element(numbers.begin(), numbers.end());
    itMax = std::max_element(numbers.begin(), numbers.end());
    return *itMax - *itMin;
}

void    Span::addNumber(vInt::iterator itBegin, vInt::iterator itEnd) {
    size_t dist  = std::distance(itBegin, itEnd);
    if (dist + numbers.size() > this->size) {
        throw outOfRange(); // out of range
    }
    for (vInt::iterator it = itBegin; it != itEnd; it++)
        numbers.push_back(*it);
}

vInt const& Span::getNumbers() const {
    return numbers;
}

std::ostream& operator<<(std::ostream& os, Span const& span) {
    vInt cpy = span.getNumbers();
    vInt::iterator it = cpy.begin();
    while (it != cpy.end()){
        os << *it++ << " ";
    }
    return os;
}