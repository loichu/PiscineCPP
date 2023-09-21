#ifndef SCALAR_CONVERTER_HPP
# define SCALAR_CONVERTER_HPP

# include <string>
# include <iostream>
# include <limits>
# include <stdlib.h>
# include <cerrno>
# include <cmath>

class ScalarConverter
{
    public:
    static void convert(std::string str);

    private:
    ScalarConverter();

    static double   getNumber(std::string str);

    class NanException          : public std::exception {};
    class OutOfRangeException   : public std::exception {};
};

#endif