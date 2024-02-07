#include <iostream>
#include <list>
#include <vector>
#include <iterator>
#include <algorithm>
#include <sstream>
#include <ctime>
#include <iomanip>

class PmergeMe
{
    private:
        std::list<int>      list;
        std::vector<int>    vector;
        double              vc_time;
        double              lst_time;
        
        bool    isDigit(std::string str);
        bool    checkArgs(int ac, char** argv);
        void    fillLists(int ac, char** argv);

        template<typename Iterator>
        void    insertionSort(Iterator begin, Iterator end);   
        void    mergeSort(std::list<int>& lst1);
        void    mergeSort(std::vector<int>& lst2);
    public:
        PmergeMe();
        PmergeMe(int ac, char** argv);
        PmergeMe(PmergeMe const& pm);
        PmergeMe& operator=(PmergeMe const& pm);
        ~PmergeMe();
};