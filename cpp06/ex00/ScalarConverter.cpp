#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{

}

ScalarConverter::ScalarConverter(const std::string target)
{
    (void)target;
}


ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
	*this = other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
    if (this != &other)
	    *this = other;
	return (*this);
}


ScalarConverter::~ScalarConverter()
{
	
}


// -------- CHECK FLOAT --------
bool ScalarConverter::CheckFloat(std::string str)
{
    int dot = 0;

    if (str.empty())
        return false;

    if (str[0] == '+' || str[0] == '-' || isdigit(str[0]))
    {
        for (size_t i = 1; i < str.length() - 1; i++)
        {
            if (str[i] == '.')
                dot++;
            else if (!isdigit(str[i]))
                return false;
        }
        if (str.length() > 0 && str[str.length() - 1] == 'f' && dot == 1)
            return true;
    }
    return false;
}


// ---------- CHECK INT ----------
bool ScalarConverter::CheckInt(const std::string& str)
{
    if (str.empty())
        return false;

    size_t start = 0;
    if (str[0] == '+' || str[0] == '-')
        start = 1;
    if (str.length() <= start)
        return false;
    for (size_t i = start; i < str.length(); ++i)
    {
        if (!std::isdigit(str[i]))
            return false;
    }
    return true;
}


// -------- CHECK DOUBLE --------
bool ScalarConverter::CheckDouble(std::string str)
{
    int dot = 0;

    if (str.empty())
        return false;

    if (str[0] == '+' || str[0] == '-' || isdigit(str[0]))
    {
        for (size_t i = 1; i < str.length(); i++)
        {
            if (str[i] == '.')
                dot++;
            else if (!isdigit(str[i]))
                return false;
        }
        return (dot == 1);
    }
    return false;
}


// -------- DETECT TYPE --------
t_type ScalarConverter::detectType(std::string literal)
{
    t_type info;

    std::memset(&info, 0, sizeof(t_type));
    if (literal == "nanf" || literal == "+inff" || literal == "-inff")
        info.FLOAT_SPECIAL = 1;

    else if (literal == "nan" || literal == "+inf" || literal == "-inf")
        info.DOUBLE_SPECIAL = 1;

    else if (literal.length() == 1 && !isdigit(literal[0]))
        info.CHAR = 1;

    else if (CheckInt(literal))
        info.INT = 1;

    else if (CheckFloat(literal))
        info.FLOAT = 1;

    else if (CheckDouble(literal))
        info.DOUBLE = 1;

    else
        info.INVALID = 1;

    return info;
}

void	ScalarConverter::printSpecial(const std::string& str)
{
    
	if (str == "nan" || str == "nanf")
	{
		std::cout << "char: impossible" << std::endl; 
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	}
	else if (str == "+inf" || str == "+inff")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
	}
	else if (str == "-inf" || str == "-inff")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
	}
}

void ScalarConverter::print_all(double base)
{
    // CHAR
    std::cout << "char: ";
    if (base < 0 || base > 127)
        std::cout << "impossible" << std::endl;
    else if (!std::isprint(static_cast<int>(base)))
        std::cout << "Non displayable" << std::endl;
    else
        std::cout << "'" << static_cast<char>(base) << "'" << std::endl;

    // INT
    std::cout << "int: ";
    if (base < INT_MIN || base > INT_MAX)
        std::cout << "impossible" << std::endl;
    else
        std::cout << static_cast<int>(base) << std::endl;

    // FLOAT
    std::cout << "float: ";
    {
        float f = static_cast<float>(base);
        if (std::isnan(base) || std::isinf(base))
            std::cout << f << "f" << std::endl;
        else if (f == static_cast<int>(f))
            std::cout << f << ".0f" << std::endl;
        else
            std::cout << f << "f" << std::endl;
    }

    // DOUBLE
    std::cout << "double: ";
    {
        if (std::isnan(base) || std::isinf(base))
            std::cout << base << std::endl;
        else if (base == static_cast<int>(base))
            std::cout << base << ".0" << std::endl;
        else
            std::cout << base << std::endl;
    }
}


void ScalarConverter::convert(std::string literal)
{
    t_type type = detectType(literal);
    double base = 0;
    int index = 0;

    if (type.CHAR) index = 1;
    else if (type.INT) index = 2;
    else if (type.FLOAT) index = 3;
    else if (type.DOUBLE) index = 4;

    if (type.DOUBLE_SPECIAL || type.FLOAT_SPECIAL)
    {
        printSpecial(literal);
        return;
    }

    switch (index)
    {
        case 1:
            base = static_cast<double>(literal[0]);
            break;

        case 2:
            base = static_cast<double>(std::stoi(literal));
            break;

        case 3:
            base = static_cast<double>(std::stof(literal));
            break;

        case 4:
            base = std::stod(literal);
            break;

        default:
            std::cout << "Invalid input\n";
            return;
    }
    print_all(base);
}

