#pragma once
#include <iostream>
#include <ostream>

struct s_data{
    std::string Char;
    std::string Int;
    std::string Float;
    std::string Double;
};

class ScalarConverter{
    private:
        ScalarConverter();
        ScalarConverter(ScalarConverter const& sc);
        ScalarConverter& operator=(ScalarConverter const& sc);
        ~ScalarConverter();
    public:
        static void     convert(std::string const& literal);
};

std::ostream& operator<<(std::ostream& os, s_data& data);