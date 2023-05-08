#include "FragTrap.hpp"

FragTrap::FragTrap (void) : ClapTrap()
{
	this->_hit = 100;
	this->_energy = 100;
	this->_attack = 30;
	std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap (std::string name) : ClapTrap(name)
{
	this->_hit = 100;
	this->_energy = 100;
	this->_attack = 30;
	std::cout << "FragTrap name constructor called" << std::endl;
}

FragTrap::~FragTrap (void)
{
	std::cout << "FragTrap destructor called" << std::endl;
}

void	FragTrap::highFivesGuys(void)
{
	if (_hit == 0)
	{
		std::cout << "FragTrap " << _name << " cannot high five, he's dead" << std::endl;
		return;
	}
	std::cout << "FragTrap " << _name << " wants a high five" << std::endl;
}
