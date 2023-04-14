#include "sed.h"

std::string	read_file(std::string filename)
{
	std::ifstream	file(filename);
	std::string		content;
	char			c;

	if (!file)
	{
		std::cerr << "Not able to open \"" << filename << "\" for reading" << std::endl;
		exit(EXIT_FAILURE);
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
		exit(EXIT_FAILURE);
  	}
	return (content);
}

void	write_file(std::string filename, std::string content)
{
	std::ofstream	file(filename);

	if (!file)
	{
		std::cerr << "Not able to open \"" << filename << "\" for writing" << std::endl;
		exit(EXIT_FAILURE);
	}
	file << content;
	file.close();
}

std::string	replace(std::string orig, char *s1, char *s2)
{
	size_t		s1_len = std::strlen(s1);
	size_t		occ_idx;
	std::string	tmp;

	while ((occ_idx = orig.find(s1)) != std::string::npos)
	{
		tmp = orig.substr(0, occ_idx);
		tmp += s2;
		tmp += orig.substr(occ_idx + s1_len);
		orig = tmp;
	}
	return (orig);
}
