#include "Dog.hpp"

Dog::Dog() : Animal()
{
	std::cout << "Dog default constructor" << std::endl;
	_type = "Dog";
}

Dog::Dog(const Dog & dog) : Animal(dog)
{
	std::cout << "Dog copy constructor" << std::endl;
}

Dog::~Dog(void)
{
	std::cout << "Dog destructor" << std::endl;
}

void	Dog::makeSound(void) const
{
	std::cout << "Bark" << std::endl;
}
