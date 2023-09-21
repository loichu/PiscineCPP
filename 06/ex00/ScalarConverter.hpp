#ifndef SCALAR_CONVERTER_HPP
# define SCALAR_CONVERTER_HPP

# include <string>
# include <iostream>
# include <limits>
# include <stdlib.h>
# include <cerrno>
# include <cmath>
// # include <ctype.h>

class ScalarConverter
{
    public:
    static void convert(std::string str);

    private:
    ScalarConverter();

    static double   getNumber(std::string str);
    // static char     getChar(double number);

    class NanException          : public std::exception {};
    class OutOfRangeException   : public std::exception {};

    // static bool isChar(std::string str);
    // static bool isNumber(std::string str);
    // static bool isInt(std::string str);
    // static bool isFloat(std::string str);
    // static bool isDouble(std::string str);

    // static void printChar(std::string str);
    // static void printInt(std::string str);
    // static void printFloat(std::string str);
    // static void printDouble(std::string str);
};

#endif