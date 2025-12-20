#include "ScalarConverter.hpp"
#include <iostream>

void printSeparator(const std::string& title)
{
    std::cout << "\n======================================" << std::endl;
    std::cout << "TEST CASE: " << title << std::endl;
    std::cout << "======================================" << std::endl;
}

int main(int argc, char* argv[])
{
    if (argc > 1)
    {
        printSeparator("Command Line Argument Test: " + std::string(argv[1]));
        ScalarConverter::convert(argv[1]);
        return 0;
    }


    // --- A. Char ---
    printSeparator("Char");
    ScalarConverter::convert("'a'");
    ScalarConverter::convert("Z");
    ScalarConverter::convert("4");
    
    printSeparator("Non-Displayable Char (ASCII 7)");
    ScalarConverter::convert("\a"); 
    
    // --- B. Int ---
    printSeparator("Int");
    ScalarConverter::convert("0");
    ScalarConverter::convert("-42");
    ScalarConverter::convert("+12345");

    printSeparator("Int Overflow/Underflow");
    ScalarConverter::convert("2147483647");
    ScalarConverter::convert("2147483648");
    ScalarConverter::convert("-2147483649");

    // --- C. Float ---
    printSeparator("Float");
    ScalarConverter::convert("0.0f");
    ScalarConverter::convert("-4.2f");
    ScalarConverter::convert("42.0f");
    ScalarConverter::convert("1.0001f");

    // --- D. Double ---
    printSeparator("Double");
    ScalarConverter::convert("0.0");
    ScalarConverter::convert("-4.2");
    ScalarConverter::convert("123.456");

    // --- E. Pseudo (Special Cases) ---
    printSeparator("Special Float/Double");
    
    // Float specials
    ScalarConverter::convert("nanf");
    ScalarConverter::convert("+inff");
    ScalarConverter::convert("-inff");

    // Double specials
    ScalarConverter::convert("nan");
    ScalarConverter::convert("+inf");
    ScalarConverter::convert("-inf");

    // --- F. Invalid Inputs ---
    printSeparator("Invalid Inputs");
    ScalarConverter::convert("Hello World");
    ScalarConverter::convert("1.2.3");
    ScalarConverter::convert("42fG");
    ScalarConverter::convert("");

    return 0;
}