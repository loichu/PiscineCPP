#include "Harl.hpp"

Harl::Harl(std::string level)
{
}

void	Harl::debug(void)
{
	std::cout << "DEBUG message" << std::endl;
}

void	Harl::info(void)
{
	std::cout << "INFO message" << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "WARNING message" << std::endl;
}

void	Harl::error(void)
{
	std::cout << "ERROR message" << std::endl;
}

void	Harl::complain(std::string level)
{
	std::string	levels[4] = {
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR"
	};
	void	(Harl::*f[4])(void) = {
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error
	};
	for (size_t i = 0; i < 4; ++i)
	{
		if (levels[i] == level)
			(this->*f[i])();
	}
}
