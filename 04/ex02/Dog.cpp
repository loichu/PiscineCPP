#include "Dog.hpp"

Dog::Dog() : Animal(), _brain(new Brain())
{
	std::cout << "Dog default constructor" << std::endl;
	_type = "Dog";
}

Dog::Dog(const Dog & dog) : Animal(dog), _brain(new Brain(*dog._brain))
{
	std::cout << "Dog copy constructor" << std::endl;
}

Dog::~Dog(void)
{
	delete _brain;
	std::cout << "Dog destructor" << std::endl;
}

Dog & Dog::operator = (const Dog & dog)
{
	*_brain = *dog._brain;
	Animal::operator=(dog);
	return *this;
}

void	Dog::makeSound(void) const
{
	std::cout << "Bark" << std::endl;
}

Brain *	Dog::getBrain(void) const
{
	return _brain;
}
