#include <iostream>
#include <map>
#include <fstream>
#include <sstream>
#include <ctime>
#include <typeinfo>
#include <unistd.h>


class file_not_found : public std::exception {
    public:
    const char* what() const throw() { 
        return "Error: could not open file.";
    }
};
class BitcoinExchange {
    private:
        std::fstream                    input_file;
        std::fstream                    db_file;
        std::stringstream               db_stream;
        std::stringstream               inpt_stream;
        std::map<std::string, double>   db;

        void    read(std::stringstream& stream, std::fstream& file);
        void    fillDb();
        bool    isValiDate(std::string history);
        bool    isNumeric(std::string str);
        bool    largeNbrCntrl(double nbr);
        bool    negativeNbrCntrl(double nbr);
        std::map<std::string, double>::iterator 
            getElementByHistory(std::string history);
    public:
        BitcoinExchange();
        BitcoinExchange(BitcoinExchange const& btc);
        BitcoinExchange& operator=(BitcoinExchange const& btc);
        BitcoinExchange(std::string fileName);
        ~BitcoinExchange();
};
