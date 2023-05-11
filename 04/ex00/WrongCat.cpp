#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
	std::cout << "WrongCat default constructor" << std::endl;
	_type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat & cat) : WrongAnimal(cat)
{
	std::cout << "WrongCat copy constructor" << std::endl;
}

WrongCat::~WrongCat(void)
{
	std::cout << "WrongCat destructor" << std::endl;
}

void	WrongCat::makeSound(void) const
{
	std::cout << "Meow" << std::endl;
}
