#include <stdlib.h>

#include <iostream>
#include <fstream>
#include <string>

std::string	read_file(std::string filename)
{
	std::ifstream	file(filename);
	std::string		content;
	char			c;

	if (!file)
	{
		std::cerr << "File named \"" << filename << "\" does not exist" << std::endl;
		exit(1);
	}
	file.exceptions(std::ifstream::badbit);
	try 
	{
		while (file.get(c)) content.append(1, c);
		file.close();
	}
	catch (std::ifstream::failure e)
	{
    	std::cerr << "Error while reading or closing file" << std::endl;
		exit(1);
  	}
	return (content);
}

int	main(int argc, char **argv)
{
	std::string input;

	if (argc != 4)
	{
		std::cerr << "Wrong number of arguments" << std::endl;
		return (1);
	}

	input = read_file(argv[1]);

	std::cout << input << std::endl;

	return (0);
}
