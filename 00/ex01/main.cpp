#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <string.h>
#include <iostream>

std::string	ask(std::string question)
{
	bool		ok = false;
	std::string	res;

	while (!ok)
	{
		std::cout << question << std::flush;
		std::getline(std::cin, res);
		if (std::cin.eof() || std::cin.bad() || std::cin.fail())
			std::exit(1);
		ok = res.length();
	}
	return (res);
}

void	add(PhoneBook& book)
{
	std::string	firstName = ask("First name: ");
	std::string	lastName = ask("Last name: ");
	std::string	nickname = ask("nickname: ");
	std::string	phoneNumber = ask("Phone number: ");
	std::string	darkestSecret= ask("Darkest secret: ");
	book.add(Contact(firstName,
					 lastName,
					 nickname,
					 phoneNumber,
					 darkestSecret));
}

int	main()
{
	PhoneBook	book;
	std::string	cmd;

	std::cout << "\x1B[2J\x1B[H";
	while (1)
	{
		std::cout << "> " << std::flush;
		std::getline(std::cin, cmd);
		if (std::cin.eof() || std::cin.bad() || std::cin.fail())
			std::exit(1);
		if (cmd.compare("ADD") == 0)
		{
			std::cout << "\x1B[2J\x1B[H";
			add(book);
		}
		else if (cmd.compare("SEARCH") == 0)
		{
			std::cout << "\x1B[2J\x1B[H";
			book.search();
		}
		else if (cmd.compare("EXIT") == 0)
			break;
		else if (cmd.length() > 0)
			std::cout << "Invalid command" << std::endl;
	}
	return (0);
}
