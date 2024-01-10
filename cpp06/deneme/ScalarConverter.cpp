#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {};

ScalarConverter::ScalarConverter(ScalarConverter const& sc) { (void)sc; }

ScalarConverter::~ScalarConverter() {};

ScalarConverter& ScalarConverter::operator=(ScalarConverter const& sc) { (void)sc; return *this; }

void ScalarConverter::convert(std::string const& literal){
    
    (void)literal;
}

std::ostream& operator<<(std::ostream& os, s_data& data){
    os << "char: " << data.Char << std::endl <<
        "int: " << data.Int << std::endl <<
        "float: " << data.Float << std::endl <<
        "double: " << data.Double << std::endl;
    return os;
}
