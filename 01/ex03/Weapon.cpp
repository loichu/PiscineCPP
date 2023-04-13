#include "Weapon.hpp"

Weapon::Weapon(void) {}

Weapon::Weapon(std::string type)
{
	_type = type;
}

std::string	Weapon::getType()
{
	return (_type);
}

void	Weapon::setType(std::string type)
{
	_type = type;
}
