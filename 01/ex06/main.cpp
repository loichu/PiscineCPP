#include "Harl.hpp"

int main(int argc, char **argv)
{
	Harl	harl;

	if (argc != 2)
	{
		std::cerr << "Expected exactly 1 argument, given " << argc - 1 << std::endl;
		return (1);
	}

	std::string	levels[4] = {
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR"
	};
	int	level = -1;
	for (size_t i = 0; i < 4; ++i)
	{
		if (levels[i] == argv[1])
		{
			level = i;
			break;
		}
	}
	if (i > 0)
	{
		std::cout << "[ " << levels[level] << " ]" << std::endl;
		harl.complain(levels[level]);
	}

	/*
	 *	As the switch statement only accepts  integers, this idea is dumb IMO
	 */
	//switch (level)
	//{
	//	case 0:
	//		std::cout << "[ " << levels[0] << " ]" << std::endl;
	//		harl.complain(levels[0]);
	//	case 1:
	//		std::cout << "[ INFO ]" << std::endl;
	//		harl.complain("INFO");
	//	case "WARNING":
	//		std::cout << "[ WARNING ]" << std::endl;
	//		harl.complain("WARNING");
	//	case "ERROR":
	//		std::cout << "[ ERROR ]" << std::endl;
	//		harl.complain("ERROR");
	//		break;
	//	default:
	//		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	//}
	return 0;
}
