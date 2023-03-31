#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iostream>

PhoneBook::PhoneBook()  : _index(0), _count(0) {}

void	PhoneBook::add(Contact contact)
{
	_contacts[_index++] = contact;
	if (_count < 8)
		++_count;
	if (_index > 7)
		_index = 0;
}

void	PhoneBook::search()
{
	int	index;

	std::cout << "|==========|==========|==========|==========|" << std::endl;
	std::cout << "|   Index  |First name| Last name| nickname |" << std::endl;
	std::cout << "|==========|==========|==========|==========|" << std::endl;
	for (int i = 0; i < _count; ++i)
		_contacts[i].print_short(i);
	std::cout << "Enter a valid index: ";
	std::cin >> index;
	if (!std::cin.good() || index < 0 || index >= _count)
	{
		std::cout << "Dumbass, this is not a valid index" << std::endl;
	}
	else
	{
		_contacts[index].print_full();
	}
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
