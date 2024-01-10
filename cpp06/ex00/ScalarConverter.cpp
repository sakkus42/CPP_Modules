#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {};


ScalarConverter::ScalarConverter(ScalarConverter const& other)
{ if (this != &other) *this = other; }


ScalarConverter::~ScalarConverter() 
{}

ScalarConverter& ScalarConverter::operator=(ScalarConverter const& other)
{ *this = other; return *this; }

const std::type_info&  ScalarConverter::whoIsType(std::string cast_str){

    try { 
        std::stoi(cast_str);
        if (cast_str.find('.') == std::string::npos) return(typeid(int));
        else std::stod("error run");
    } catch (const std::invalid_argument&) { 
        std::cout << "error" << std::endl;
    }

    if (cast_str.find('.') != std::string::npos){
        try {
            std::stod(cast_str);
            std::cout << std::stod(cast_str) << std::endl;
            if (cast_str.find('f') == std::string::npos) return(typeid(double));
            else std::stod("error run");
        } catch (const std::invalid_argument&) { }

        try { 
            std::stof(cast_str);
            return(typeid(float));
        } catch (const std::invalid_argument&) { }        
    }

    if (cast_str.length() == 1) { return(typeid(char)); }
    return (typeid(false));
}



void ScalarConverter::convert(std::string cast_string){
    const std::type_info& type = ScalarConverter::whoIsType(cast_string);
    std::cout << type.name() << std::endl;
}


