#ifndef SCALAR_CONVERTER_CPP
#define SCALAR_CONVERTER_CPP

#include <iostream>
#include <string>
#include <climits>
#include <cmath>
#include <cstring>
#include <cstdlib>


typedef struct s_type {
    int CHAR;
    int INT;
    int FLOAT;
    int DOUBLE;
    int FLOAT_SPECIAL;
    int DOUBLE_SPECIAL;
    int INVALID;
} t_type;


class ScalarConverter
{
	public:
        static void convert(std::string literal);
	private:
		ScalarConverter();
		ScalarConverter(const std::string target);
		ScalarConverter(const ScalarConverter &other);
		ScalarConverter &operator=(const ScalarConverter &other);
		~ScalarConverter();
        static void	printSpecial(const std::string& str);
        static t_type detectType(std::string literal);
        static bool CheckFloat(std::string str);
        static bool CheckInt(const std::string& str);
        static bool CheckDouble(std::string str);

        static void print_all(double base);



};



#endif