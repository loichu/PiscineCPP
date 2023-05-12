#include "Cat.hpp"

Cat::Cat() : Animal()
{
	std::cout << "Cat default constructor" << std::endl;
	_type = "Cat";
}

Cat::Cat(const Cat & cat) : Animal(cat)
{
	std::cout << "Cat copy constructor" << std::endl;
}

Cat::~Cat(void)
{
	std::cout << "Cat destructor" << std::endl;
}

void	Cat::makeSound(void) const
{
	std::cout << "Meow" << std::endl;
}
