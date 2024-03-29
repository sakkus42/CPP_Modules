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
            std::string chrStr;
            std::string itStr;
            std::string fltStr;
            std::string dblStr;
		} type_value;
        ScalarConverter();
        ~ScalarConverter();
        ScalarConverter(ScalarConverter const& other);
        ScalarConverter& operator=(ScalarConverter const& other);
    public:
        static void convert(std::string cast_string);
};
