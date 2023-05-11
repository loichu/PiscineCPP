#include "FragTrap.hpp"

FragTrap::FragTrap (void) : ClapTrap()
{
	std::cout << "FragTrap default constructor called" << std::endl;
	this->_hit = 100;
	this->_energy = 100;
	this->_attack = 30;
}

FragTrap::FragTrap (std::string name) : ClapTrap(name)
{
	std::cout << "FragTrap name constructor called" << std::endl;
	this->_hit = 100;
	this->_energy = 100;
	this->_attack = 30;
}

FragTrap::FragTrap (const FragTrap & frag) : ClapTrap(frag)
{
	std::cout << "FragTrap copy constructor called" << std::endl;
	//std::cout << "Hit points: " << _hit << std::endl;
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
