#include "ScalarConverter.hpp"

void ScalarConverter::convert(std::string str)
{
    // Just for inf
    size_t  inf_pos = str.find("inf");
    if (inf_pos != std::string::npos)
    {
        if (inf_pos == 0 || (inf_pos == 1 && str[0] == '+'))
        {
            std::cout << "char: out-of-range" << std::endl;
            std::cout << "int: out-of-range" << std::endl;
            std::cout << "float: +inff" << std::endl;
            std::cout << "double: +inf" << std::endl;
            return;
        }
        else if (inf_pos == 1 && str[0] == '-')
        {
            std::cout << "char: out-of-range" << std::endl;
            std::cout << "int: out-of-range" << std::endl;
            std::cout << "float: -inff" << std::endl;
            std::cout << "double: -inf" << std::endl;
            return;
        }
    }

    // Standard execution
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
            std::cout << "float: " << static_cast<float>(number)
                                   << (std::fmod(number, 1) ? "f" : ".0f")
                                   << std::endl;
        else
            std::cout << "float: out-of-range" << std::endl;

        // DOUBLE
        std::cout << "double: "
                  << number
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