#include "ScalarConverter.hpp"

void ScalarConverter::convert(std::string str)
{
    std::cout << str << std::endl;
}

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(ScalarConverter & converter)
{
    *this = converter;
}

ScalarConverter::~ScalarConverter() {}

ScalarConverter &ScalarConverter::operator=(ScalarConverter &converter)
{
    (void) converter;
    return *this;
}

bool ScalarConverter::isChar(std::string str)
{
    return str.length() == 1;
}

bool ScalarConverter::isNumber(std::string str)
{
    return false;
}

bool ScalarConverter::isInt(std::string str)
{
    int start = str[0] == '-' || str[0] == '+' ? 1 : 0;
    for (int i = start; i < str.length(); ++i)
    {
        if (!std::isdigit(str[i]))
            return false;
    }
    return true;
}

bool ScalarConverter::isFloat(std::string str)
{
    if (str[str.length() - 1] != 'f')
        return false;

    bool    dec = false;
    int     start = str[0] == '-' || str[0] == '+' ? 1 : 0;
    for (int i = start; i < str.length() - 1; ++i)
    {
        if (str[i] == '.')
        {
            if (dec)
                return false;
            else
                dec = true;
        }
        if (!std::isdigit(str[i]) && str[i] != '.')
            return false;
    }
    return true;
}

bool ScalarConverter::isDouble(std::string str)
{
    bool    dec = false;
    int     start = str[0] == '-' || str[0] == '+' ? 1 : 0;
    for (int i = start; i < str.length(); ++i)
    {
        if (str[i] == '.')
        {
            if (dec)
                return false;
            else
                dec = true;
        }
        if (!std::isdigit(str[i]) && str[i] != '.')
            return false;
    }
    return dec;
}
