#include <iostream>
#include <list>
#include <vector>
#include <sstream>

class PmergeMe
{
    private:
        std::list<unsigned int> list1;
        std::vector<unsigned int> list2;

        bool    isDigit(std::string str);
        bool    checkArgs(int ac, char** argv);
        void    fillLists(int ac, char** argv);
    public:
        PmergeMe();
        PmergeMe(int ac, char** argv);
        PmergeMe(PmergeMe const& pm);
        PmergeMe& operator=(PmergeMe const& pm);
        ~PmergeMe();
};