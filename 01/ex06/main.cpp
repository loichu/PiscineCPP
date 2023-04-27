#include "Harl.hpp"

int main(int argc, char **argv)
{
	Harl	harl;

	if (argc != 2)
	{
		std::cerr << "Expected exactly 1 argument, given " << argc - 1 << std::endl;
		return (1);
	}
	harl.complain(argv[1]);
	return 0;
}
