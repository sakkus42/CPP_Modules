#include "ScalarConverter.hpp"

ScalarConverter::TypeValue ScalarConverter::type_value = {0, 0, 0.0f, 0.0, "", "", "", ""};


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
	int flIndex = cast_str.find('f');
	int dotIndex = cast_str.find('.');
	std::string uniqInpt[] = {"nan", "+inf", "-inf", "inf"};
	std::string uniqInptF[] = {"nanf", "+inff", "-inf", "inff"};
	for (size_t i = 0; i < 4; i++)
		if (cast_str.find(uniqInpt[i]) != std::string::npos || cast_str.find(uniqInptF[i]) != std::string::npos){
			ScalarConverter::type_value.dblStr = uniqInpt[i];
			ScalarConverter::type_value.fltStr = uniqInptF[i];
			std::cout << uniqInptF[i]<< std::endl;
			return true;
		}	
	if (cast_str[0] == '+' || cast_str[0] == '-')
		cast_str.erase(0, 1);
	if (cast_str.length() == 1)
		return true;
	if (flIndex != -1 && dotIndex != -1 && dotIndex > flIndex)
		return false;
	if (flIndex != -1 && cast_str[flIndex + 1])
		return false;
	(void)(dotIndex != -1 && (cast_str.erase(dotIndex, 1) == ""));
	(void)(flIndex != -1 && (cast_str.erase(dotIndex != -1 ? flIndex - 1 : flIndex, 1) == ""));
	if (!isDigit(cast_str))
		return false;

	return true;
}

const std::type_info&  ScalarConverter::whoIsType(std::string cast_str){

	if (cast_str[0] == '+' || cast_str[0] == '-')
		cast_str.erase(0, 1);
	bool isDot = cast_str.find('.') == std::string::npos;
	bool isFloat = cast_str.find('f') == std::string::npos;
    try {
        std::stoi(cast_str);
        if (isDot && isFloat) 
			return(typeid(int));
    } catch (const std::invalid_argument&) { 
    } catch (const std::out_of_range&) {
		ScalarConverter::type_value.itStr = "imposible";
		ScalarConverter::type_value.chrStr = "imposible";
	}


	

	if (cast_str.length() == 1) {
		return(typeid(char));
	}
	
	try { 
		std::stof(cast_str);
		if (!isFloat) return(typeid(float));
		std::stoi(cast_str);
	} catch (const std::invalid_argument&) {
	} catch (const std::out_of_range&) {
	}

	try {
		std::stod(cast_str);
		return (typeid(double));
	} catch (const std::invalid_argument&) { 
	} catch (const std::out_of_range&) {
	}

    return (typeid(false));
}



void ScalarConverter::convert(std::string cast_string){
	const bool validStr = validString(cast_string);
	if (!validStr) {
		std::cout <<
			"char: impossible" << std::endl <<
			"int: impossible" << std::endl <<
			"float: impossible" << std::endl <<
			"double: impossible" << std::endl;
			return;
	} else if (type_value.dblStr != "" || type_value.fltStr != "" ) {
		std::cout <<
			"char: impossible" << std::endl <<
			"int: impossible" << std::endl <<
			"float: " << type_value.fltStr << std::endl << 
			"double: " << type_value.dblStr << std::endl;
			return;
	}

    const std::type_info& type = whoIsType(cast_string);
	if (type == typeid(char)){
		type_value.chr = cast_string[0];
		type_value.it = static_cast<int>(type_value.chr);
		type_value.flt = static_cast<float>(type_value.chr);
		type_value.dbl = static_cast<double>(type_value.chr);
	}else if (type == typeid(int)) {
		type_value.it = std::stoi(cast_string);
		type_value.chr = static_cast<char>(type_value.it);
		type_value.flt = static_cast<float>(type_value.it);
		type_value.dbl = static_cast<double>(type_value.it);
	} else if (type == typeid(float)) {
		type_value.flt = std::stof(cast_string);
		type_value.chr = static_cast<char>(type_value.flt);
		type_value.it = static_cast<int>(type_value.flt);
		type_value.dbl = static_cast<double>(type_value.flt);
	} else if (type == typeid(double)) {
		type_value.dbl = std::stod(cast_string);
		type_value.chr = static_cast<char>(type_value.dbl);
		type_value.it = static_cast<int>(type_value.dbl);
		type_value.flt = static_cast<float>(type_value.dbl);
	}
	
	if (type_value.chrStr.compare(""))
		std::cout << "char: " << type_value.chrStr << std::endl;
	else
		std::cout << "char: " <<  (isprint(type_value.chr) ? std::string(1, type_value.chr) : std::string("Non displayed"))  << std::endl;
	if (type_value.itStr.compare(""))
		std::cout << "int: " << type_value.itStr  << std::endl;
	else
		std::cout << "int: " << type_value.it  << std::endl;
	if (type_value.fltStr.compare(""))
		std::cout << "float :"  << type_value.fltStr  << std::endl;
	else
		std::cout << "float :"  << type_value.flt << "f" << std::endl;
	if (type_value.dblStr.compare(""))
		std::cout << "double: " << type_value.dblStr << std::endl;
	else
		std::cout << "double: " << type_value.dbl << std::endl;
}