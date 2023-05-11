#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "WrongAnimal default constructor" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal & animal)
{
	std::cout << "WrongAnimal copy constructor" << std::endl;
	*this = animal;
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "WrongAnimal destructor" << std::endl;
}

WrongAnimal & WrongAnimal::operator = (const WrongAnimal & animal)
{
	_type = animal._type;
	return *this;
}

std::string	WrongAnimal::getType(void) const
{
	return _type;
}

void	WrongAnimal::makeSound(void) const
{
	std::cout << "Grrr" << std::endl;
}
