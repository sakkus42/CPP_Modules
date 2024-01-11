#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {};


ScalarConverter::ScalarConverter(ScalarConverter const& other)
{ if (this != &other) *this = other; }


ScalarConverter::~ScalarConverter() 
{}

ScalarConverter& ScalarConverter::operator=(ScalarConverter const& other) {
	(void)other;
	return *this;
}

bool ScalarConverter::isDigit(std::string cast_string) {
	for (size_t i = 0; i < cast_string.length(); i++){
		if (!isdigit(cast_string[i])) {
			return false;
		}
	}
	return true;
}

bool  ScalarConverter::validString(std::string cast_str){
	if (cast_str.length() == 1) 
		return true;

	int flIndex = cast_str.find('f');
	int dotIndex = cast_str.find('.');

	if (dotIndex > flIndex)
		return false;
	if (flIndex != -1 && cast_str[flIndex + 1])
		return false;
	(void)(dotIndex != -1 && (cast_str.erase(dotIndex, 1) == ""));
	(void)(flIndex != -1 && (cast_str.erase(flIndex - 1, 1) == ""));
	if (!isDigit(cast_str))
		return false;
	return true;
}

const std::type_info&  ScalarConverter::whoIsType(std::string cast_str){

	bool isDot = cast_str.find('.') == std::string::npos;

    try { 
        std::stoi(cast_str);
        if (isDot) return(typeid(int));
        else std::stod("error run");
    } catch (const std::invalid_argument&) { 
    }

    if (!isDot){
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
	const bool validStr = ScalarConverter::validString(cast_string);
	if (!validStr) {
		std::cout <<
			"char: impossible" << std::endl <<
			"int: impossible" << std::endl <<
			"float: impossible" << std::endl <<
			"double: impossible" << std::endl;
			return;
	}
    const std::type_info& type = ScalarConverter::whoIsType(cast_string);
    std::cout << type.name() << std::endl;
}


