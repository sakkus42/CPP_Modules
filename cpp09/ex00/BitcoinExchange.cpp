#include "BitcoinExchange.hpp"
BitcoinExchange::BitcoinExchange() {};
BitcoinExchange::BitcoinExchange(BitcoinExchange const& btc) {
    if (this != &btc) {
        *this = btc;
    }
};
BitcoinExchange& BitcoinExchange::operator=(BitcoinExchange const& btc) {
    if (this == &btc) 
        this->db = btc.db;
    return *this;
}
BitcoinExchange::BitcoinExchange(std::string fileName) : 
input_file(fileName.c_str()), db_file("data.csv") {
    db_file.is_open() ? read(db_stream, db_file) : throw file_not_found();
    input_file.is_open() ? read(inpt_stream, input_file) : throw file_not_found();
    fillDb();
    std::string line, date;
    std::getline(inpt_stream, line);
    double value;
    while (std::getline(inpt_stream, line)) {
        std::stringstream ss(line);
        if (std::getline(ss, date, '|') && ss >> value) {
            std::map<std::string, double>::iterator it = getElementByHistory(date.erase(date.length() - 1, 1));
            if (it != db.end() && largeNbrCntrl(value))
                std::cout << "Error: too large a number." << std::endl;
            else if (it != db.end() && negativeNbrCntrl(value))
                std::cout << "Error: not a positive number." << std::endl;
            else if (it != db.end())
                std::cout << date << " => " << value << " = " << it->second * value << std::endl;
            else
                std::cout << "Error: bad input => " << date << std::endl;
        } else {
            std::cout << "Error: bad input => " << date << std::endl;
        }
    }
    
}

BitcoinExchange::~BitcoinExchange() {
    if (db_file.is_open()) db_file.close();
    if (input_file.is_open()) input_file.close();
}

void    BitcoinExchange::read(std::stringstream& stream, std::fstream& file) {
    std::string out;
    while (file.good()) {
            std::getline(file, out);
            stream << out + "\n";
    }
}

void    BitcoinExchange::fillDb() {
    std::string date;
    double      value;
    while (this->db_stream >> date){
        std::stringstream ss(date);
        std::getline(ss, date, ',');
        ss >> value;
        this->db[date] = value;
    }
}

bool    BitcoinExchange::negativeNbrCntrl(double nbr) {
    if (nbr < 0.0) {
        return true;
    }
    return false;
}

bool BitcoinExchange::largeNbrCntrl(double nbr) {
    if (nbr < 1000.0) {
        return false;
    }
    return true;
}

bool BitcoinExchange::isNumeric(std::string str) {
    for (size_t i = 0; i < str.length(); i++)
        if (!std::isdigit(str[i]))
            return false;
    return true;
}

bool BitcoinExchange::isValiDate(std::string history) {
    std::stringstream ss(history);
    std::string year, month, day;
    std::getline(ss, year, '-');
    std::getline(ss, month, '-');
    std::getline(ss, day, '-');
    if (year.length() == 4 && month.length() == 2 && day.length() == 2 
        && isNumeric(year) && isNumeric(month) && isNumeric(day) 
        && std::stoi(month) <= 12 && std::stoi(day) <= 31)
        return true;
    return false;
}

std::map<std::string, double>::iterator
BitcoinExchange::getElementByHistory(std::string history) {
    std::map<std::string, double>::iterator it = db.find(history);
    if (it != db.end()) {
        return it;   
    } else if (isValiDate(history)) {
        db[history];
        it = --db.find(history);
        db.erase(history);
        return it;
    }
    std::cout << history << std::endl;
    return db.end();
}