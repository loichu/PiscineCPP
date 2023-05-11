#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "Animal default constructor" << std::endl;
}

Animal::Animal(const Animal & animal)
{
	std::cout << "Animal copy constructor" << std::endl;
	*this = animal;
}

Animal::~Animal(void)
{
	std::cout << "Animal destructor" << std::endl;
}

Animal & Animal::operator = (const Animal & animal)
{
	_type = animal._type;
	return *this;
}

std::string	Animal::getType(void) const
{
	return _type;
}

void	Animal::makeSound(void) const
{
	std::cout << "Grrr" << std::endl;
}
