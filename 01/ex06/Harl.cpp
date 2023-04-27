#include "Harl.hpp"

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
	int	log_level = -1;

	std::string	levels[4] = {
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR"
	};
	for (size_t i = 0; i < 4; ++i)
	{
		if (levels[i] == level)
		{
			log_level = i;
			break;
		}
	}
	switch (log_level)
	{
		case 0:
			std::cout << "[ DEBUG ]" << std::endl;
			debug();
			std::cout << std::endl;
		case 1:
			std::cout << "[ INFO ]" << std::endl;
			info();
			std::cout << std::endl;
		case 2:
			std::cout << "[ WARNING ]" << std::endl;
			warning();
			std::cout << std::endl;
		case 3:
			std::cout << "[ ERROR ]" << std::endl;
			error();
			std::cout << std::endl;
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
}
