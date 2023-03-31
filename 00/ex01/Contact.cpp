#include "Contact.hpp"
#include <iostream>
#include <string>

Contact::Contact(){}

Contact::~Contact(){}

Contact::Contact(std::string firstName,
                 std::string lastName,
                 std::string nickname,
                 std::string phoneNumber,
                 std::string darkestSecret)
{
	_firstName = firstName;
	_lastName = lastName;
	_nickname = nickname;
	_phoneNumber = phoneNumber;
	_darkestSecret = darkestSecret;
}

void Contact::print_column(std::string str)
{
	int	len = str.length();

	std::cout << "|";
	if (len > 10)
	{
		str = str.substr(0, 10);
		str[9] = '.';
	}
	else
	{
		str = std::string(10 - len, ' ') + str; 
	}
	std::cout << str;
}

void Contact::print_short(int index)
{
	std::string	str_index(1, index + 48);

	print_column(str_index);
	print_column(_firstName);
	print_column(_lastName);
	print_column(_nickname);
	std::cout << "|" << std::endl;
}

void Contact::print_full()
{
	std::cout << "First name: " << _firstName << std::endl;
	std::cout << "Last name: " << _lastName << std::endl;
	std::cout << "nickname: " << _nickname << std::endl;
	std::cout << "Phone number: " << _phoneNumber << std::endl;
	std::cout << "Darkest secret: " << _darkestSecret << std::endl;
}
