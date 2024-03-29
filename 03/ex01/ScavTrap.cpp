#include "ScavTrap.hpp"

ScavTrap::ScavTrap (void) : ClapTrap()
{
	std::cout << "ScavTrap default constructor called" << std::endl;
	this->_hit = 100;
	this->_energy = 50;
	this->_attack = 20;
}

ScavTrap::ScavTrap (std::string name) : ClapTrap(name)
{
	std::cout << "ScavTrap name constructor called" << std::endl;
	this->_hit = 100;
	this->_energy = 50;
	this->_attack = 20;
}

ScavTrap::ScavTrap (const ScavTrap & scav) : ClapTrap(scav)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
	//std::cout << "Hit points: " << _hit << std::endl;
}

ScavTrap::~ScavTrap (void)
{
	std::cout << "ScavTrap destructor called" << std::endl;
}

void	ScavTrap::attack(const std::string & target)
{
	if (_hit == 0 || _energy == 0)
	{
		std::cout << "ScavTrap " << _name << " cannot attack" << std::endl;
		return;
	}
	std::cout << "ScavTrap " << _name << " attacks " << target
			  << ", causing " << _attack << " points of damage! "
			  << --_energy << " energy points left"
			  << std::endl;
}

void	ScavTrap::guardGate(void)
{
	if (_hit == 0)
	{
		std::cout << "ScavTrap " << _name << " cannot guard, he's dead" << std::endl;
		return;
	}
	std::cout << "ScavTrap " << _name << " entered gate keeper mode" << std::endl;
}
