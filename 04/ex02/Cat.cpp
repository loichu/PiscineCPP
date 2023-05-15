#include "Cat.hpp"

Cat::Cat() : Animal()
{
	std::cout << "Cat default constructor" << std::endl;
	_type = "Cat";
	_brain = new Brain();
}

Cat::Cat(const Cat & cat) : Animal(cat)
{
	std::cout << "Cat copy constructor" << std::endl;
	_brain = new Brain(*cat._brain);
}

Cat::~Cat(void)
{
	delete _brain;
	std::cout << "Cat destructor" << std::endl;
}

Cat & Cat::operator = (const Cat & cat)
{
	std::cout << "Assign Cat" << std::endl;
	*_brain = *cat._brain;
	Animal::operator=(cat);
	return *this;
}

void	Cat::makeSound(void) const
{
	std::cout << "Meow" << std::endl;
}

Brain *	Cat::getBrain(void) const
{
	return _brain;
}
