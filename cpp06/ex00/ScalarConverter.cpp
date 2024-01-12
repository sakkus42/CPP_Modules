#include "ScalarConverter.hpp"

ScalarConverter::TypeValue ScalarConverter::type_value = {0, 0, 0.0f, 0.0};


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

	if (cast_str.length() == 1) { 
		return(typeid(char));
	}

	bool isDot = cast_str.find('.') == std::string::npos;
    try {
		std::cout << "burdayım" << std::endl;
        std::stoi(cast_str);
        if (isDot) return(typeid(int));
        else std::stod("error run");
    } catch (const std::invalid_argument&) { 
    } catch (const std::out_of_range&) {
	}
	
	try {
		std::stod(cast_str);
		std::cout << std::stod(cast_str) << std::endl;
		if (cast_str.find('f') == std::string::npos) return(typeid(double));
		else std::stod("error run");
	} catch (const std::invalid_argument&) { 
	} catch (const std::out_of_range&) {
	}

	try { 
		std::stof(cast_str);
		return(typeid(float));
	} catch (const std::invalid_argument&) {
	} catch (const std::out_of_range&) {
	}

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
	switch	(*type.name()) {
		case 'c':
			ScalarConverter::type_value.it = cast_string[0];
			break;
		case 'i':
			ScalarConverter::type_value.it = std::stoi(cast_string);
			break;
		case 'f':
			ScalarConverter::type_value.it = std::stof(cast_string);
			break;
		case 'd':
			ScalarConverter::type_value.it = std::stod(cast_string);
			break;
	}
}


