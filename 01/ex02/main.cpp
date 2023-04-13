#include <iostream>
#include <string>

int	main(void)
{
	std::string	stringMEM = "HI THIS IS BRAIN";
	std::string	*stringPTR = &stringMEM;
	std::string	&stringREF = stringMEM;

	// Print addresses
	std::cout << "Addresses:" << std::endl;
	std::cout << "String in memory: " << (void *)&stringMEM << std::endl;
	std::cout << "String pointer *: " << (void *)&stringPTR << std::endl;
	std::cout << "String reference: " << (void *)&stringREF << std::endl;

	std::cout << std::endl;

	// Print values
	std::cout << "Values:" << std::endl;
	std::cout << "String in memory: " << stringMEM << std::endl;
	std::cout << "String pointer *: " << stringPTR << std::endl;
	std::cout << "String reference: " << stringREF << std::endl;
}
