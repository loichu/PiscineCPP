#include "ScalarConverter.hpp"

void ScalarConverter::convert(std::string str)
{
    // bool is_char = (str.length() == 1 && std::isprint(str[0]));

    // if (is_char)
    //     std::cout << "char: " << str[0] << std::endl;

    try
    {
        double number   = getNumber(str);

        // CHAR
        if (number >= 0 && number <= std::numeric_limits<char>::max())
        {
            if (std::isprint(number))
                std::cout << "char: '" << static_cast<char>(number) << "'" << std::endl;
            else
                std::cout << "char: Non displayable" << std::endl;
        }
        else
        {
            std::cout << "char: out-of-range" << std::endl;
        }

        // INT
        if (number >= std::numeric_limits<int>::min() && number <= std::numeric_limits<int>::max())
            std::cout << "int: " << static_cast<int>(number) << std::endl;
        else
            std::cout << "int: out-of-range" << std::endl;

        // FLOAT
        if (number >= -std::numeric_limits<float>::max() && number <= std::numeric_limits<float>::max())
            std::cout << "float: " //<< std::fixed
                                   << static_cast<float>(number)
                                   << (std::fmod(number, 1) ? "f" : ".0f")
                                   << std::endl;
        else
            std::cout << "float: out-of-range" << std::endl;

        // DOUBLE
        std::cout << "double: " //<< std::fixed
                  << static_cast<double>(number)
                  << (std::fmod(number, 1) ? "" : ".0")
                  << std::endl;
        
    }
    catch (NanException & e)
    {
        if (str.length() > 1)
            std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
    }
    catch (OutOfRangeException & e)
    {
        std::cout << "char: out-of-range" << std::endl;
        std::cout << "int: out-of-range" << std::endl;
        std::cout << "float: out-of-range" << std::endl;
        std::cout << "double: out-of-range" << std::endl;
    }
}

double ScalarConverter::getNumber(std::string str)
{
    bool    dot     = false;
    int     index   = (str[0] == '+' || str[0] == '-') ? 0 : -1;
    int     len     = str.length();
    double  number  = 0;

    if (str.length() == 1 && std::isprint(str[0]))
        return static_cast<double>(str[0]); 

    while (++index < len)
    {
        if (str[index] == '.')
        {
            if (dot)
                throw NanException();
            dot = true;
            continue;
        }
        if (str[index] == 'f' && len == index + 1)
            break;
        if (!std::isdigit(str[index]))
            throw NanException();
    }

    number = std::strtod(str.c_str(), NULL);
    if (errno == ERANGE)
        throw OutOfRangeException();


    return number;
}

// char ScalarConverter::getChar(std::string str)
// {
//     if (str.length() == 1)
//         return str[0];
    
//     return 0;
// }

// char ScalarConverter::getChar(double number)
// {
//     return 0;
// }

// ScalarConverter::ScalarConverter() {}

// bool ScalarConverter::isChar(std::string str)
// {
//     return str.length() == 1;
// }

// bool ScalarConverter::isNumber(std::string str)
// {
//     return false;
// }

// bool ScalarConverter::isInt(std::string str)
// {
//     int start = str[0] == '-' || str[0] == '+' ? 1 : 0;
//     for (int i = start; i < str.length(); ++i)
//     {
//         if (!std::isdigit(str[i]))
//             return false;
//     }
//     return true;
// }

// bool ScalarConverter::isFloat(std::string str)
// {
//     if (str[str.length() - 1] != 'f')
//         return false;

//     bool    dec = false;
//     int     start = str[0] == '-' || str[0] == '+' ? 1 : 0;
//     for (int i = start; i < str.length() - 1; ++i)
//     {
//         if (str[i] == '.')
//         {
//             if (dec)
//                 return false;
//             else
//                 dec = true;
//         }
//         if (!std::isdigit(str[i]) && str[i] != '.')
//             return false;
//     }
//     return true;
// }

// bool ScalarConverter::isDouble(std::string str)
// {
//     bool    dec = false;
//     int     start = str[0] == '-' || str[0] == '+' ? 1 : 0;
//     for (int i = start; i < str.length(); ++i)
//     {
//         if (str[i] == '.')
//         {
//             if (dec)
//                 return false;
//             else
//                 dec = true;
//         }
//         if (!std::isdigit(str[i]) && str[i] != '.')
//             return false;
//     }
//     return dec;
// }
