#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {};
PmergeMe::PmergeMe(PmergeMe const& pm) {
    if (this != &pm) *this = pm;
}
PmergeMe& PmergeMe::operator=(PmergeMe const& pm) {
    if (this != &pm){
        this->list1 = pm.list1;
        this->list2 = pm.list2;
    }
    return *this;
}
PmergeMe::~PmergeMe() {};

PmergeMe::PmergeMe(int ac, char** argv) {
    if (checkArgs(ac, argv))
        throw std::runtime_error("Error: Invalid argument");
    fillLists(ac, argv);
}

void PmergeMe::fillLists(int ac, char** argv) {
    for (int i = 0; i < ac; i++) {
        try {
            int nbr = std::stoi(argv[i]);
            list1.push_back(nbr);
            list2.push_back(nbr);
        } catch(const std::exception& e) {
            std::cerr << e.what() << std::endl;
            exit(0);
        }
    }
}

bool PmergeMe::checkArgs(int ac, char** argv) {
    for (int i = 0; i < ac; i++) 
        if (!isDigit(std::string(argv[i]))) return true;
    return false;
}

bool PmergeMe::isDigit(std::string str) {
    for (size_t i = 0; i < str.length(); i++)
        if (!std::isdigit(str[i]))
            return false;
    return true;
}