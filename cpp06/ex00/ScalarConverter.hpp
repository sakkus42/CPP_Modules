#include <iostream>
#include <typeinfo>
#include <string>

class ScalarConverter {
    private:
        static const std::type_info& whoIsType(std::string cast_string);
        static bool validString(std::string cast_string);
		static bool isDigit(std::string cast_string);
		static struct TypeValue{
			char	chr;
			int		it;
			float	flt;
			double	dbl;
		} type_value;
    public:
        ScalarConverter();
        ~ScalarConverter();
        ScalarConverter(ScalarConverter const& other);
        ScalarConverter& operator=(ScalarConverter const& other);
        static void convert(std::string cast_string);
};
