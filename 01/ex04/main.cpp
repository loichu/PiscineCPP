#include "sed.h"

int	main(int argc, char **argv)
{
	std::string input;
	std::string output;

	if (argc != 4)
	{
		std::cerr << "Wrong number of arguments" << std::endl;
		return (EXIT_FAILURE);
	}
	if (std::strlen(argv[2]) == 0)
	{
		std::cerr << "The searched string cannot be empty" << std::endl;
		return (EXIT_FAILURE);
	}

	input = read_file(argv[1]);
	output = replace(input, argv[2], argv[3]);
	write_file(std::string(argv[1]) + ".replace", output);

	return (EXIT_SUCCESS);
}
