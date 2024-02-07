#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {};
PmergeMe::PmergeMe(PmergeMe const& pm) {
    if (this != &pm) *this = pm;
}
PmergeMe& PmergeMe::operator=(PmergeMe const& pm) {
    if (this != &pm){
        this->list = pm.list;
        this->vector = pm.vector;
    }
    return *this;
}
PmergeMe::~PmergeMe() {};

PmergeMe::PmergeMe(int ac, char** argv) {
    if (checkArgs(ac, argv))
        throw std::runtime_error("Error: Invalid argument");
    fillLists(ac, argv);
    mergeSort(list);
    mergeSort(vector);

    std::cout << "After:    ";
    for (std::list<int>::iterator el = list.begin(); el != list.end(); el++)
        std::cout << *el << " ";
    std::cout << std::endl;
    std::cout << "Time to process a range of " << list.size() <<
    " elements with std::list   : " << std::fixed << std::setprecision(4) 
    << this->lst_time * 1'000'000 << " us" << std::endl;
    std::cout << "Time to process a range of " << list.size() <<
    " elements with std::vector : " << std::fixed << std::setprecision(4) 
    << this->vc_time * 1'000'000 << " us" << std::endl;
    
}

template<typename Iterator>
void PmergeMe::insertionSort(Iterator begin, Iterator end) {
    Iterator it, key, prev;
    for (it = std::next(begin); it != end; it++) {
        key = it;
        prev = std::prev(it);
        while (key != begin && *prev > *key) {
            std::swap(*prev, *key);
            prev = std::prev(prev);
            key = std::prev(key);
        }
    }
}


void  PmergeMe::mergeSort(std::list<int>& list) {
    std::clock_t start = clock();
    if (list.size() < 5) {
        insertionSort(list.begin(), list.end());
        std::clock_t end = clock();
        this->lst_time = (double)(end - start) / CLOCKS_PER_SEC;
        return;
    }
    std::list<int>::iterator it_begin = list.begin();   
    std::list<int>::iterator it_end = list.end();
    std::list<int>::iterator it_mid = list.begin();
    std::advance(it_mid, list.size() / 2);
    std::list<int> leftSubList(it_begin, it_mid);
    std::list<int> rightSubList(it_mid, it_end);
    mergeSort(leftSubList);
    mergeSort(rightSubList);
    std::merge(leftSubList.begin(), leftSubList.end(), rightSubList.begin(), rightSubList.end(), list.begin());
    std::clock_t end = clock();
    this->lst_time = (double)(end - start) / CLOCKS_PER_SEC;
}

void  PmergeMe::mergeSort(std::vector<int>& vector) {
    std::clock_t start = clock();
    if (vector.size() < 5) {
        insertionSort(vector.begin(), vector.end());
        std::clock_t end = clock();
        this->vc_time = (double)(end - start) / CLOCKS_PER_SEC;
        return;
    }
    std::vector<int>::iterator it_begin = vector.begin();   
    std::vector<int>::iterator it_end = vector.end();
    std::vector<int>::iterator it_mid = vector.begin() + (vector.end() - vector.begin()) / 2;
    std::vector<int> leftSubVector(it_begin, it_mid);
    std::vector<int> rightSubVector(it_mid, it_end);
    mergeSort(leftSubVector);
    mergeSort(rightSubVector);
    std::merge(leftSubVector.begin(), leftSubVector.end(), rightSubVector.begin(), rightSubVector.end(), vector.begin());
    std::clock_t end = clock();
    this->vc_time = (double)(end - start) / CLOCKS_PER_SEC;
}

void PmergeMe::fillLists(int ac, char** argv) {
    std::stringstream ss;
    for (int i = 0; i < ac; i++) {
        try {
            int nbr = std::stoi(argv[i]);
            list.push_back(nbr);
            vector.push_back(nbr);
            ss << nbr << " ";
        } catch(const std::exception& e) {
            std::cerr << e.what() << std::endl;
            exit(0);
        }
    }
    std::cout << "Before:   " << ss.str() << std::endl;
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