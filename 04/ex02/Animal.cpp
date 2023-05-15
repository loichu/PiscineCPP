#include "Animal.hpp"

Animal::Animal() : _type("undefined"), _brain(new Brain())
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
	delete _brain;
}

Animal & Animal::operator = (const Animal & animal)
{
	_type = animal._type;
	*_brain = *(animal._brain);
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

Brain *	Animal::getBrain(void) const
{
	return _brain;
}
