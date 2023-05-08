#include "ClapTrap.hpp"

ClapTrap::ClapTrap (void) : _hit(10), _energy(10), _attack(0)
{
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap (const ClapTrap & clap)
{
	std::cout << "ClapTrap copy constructor called" << std::endl;
	*this = clap;
}

ClapTrap::ClapTrap (std::string name) : _name(name), _hit(10), _energy(10), _attack(0)
{
	std::cout << "ClapTrap name constructor called" << std::endl;
}

ClapTrap::~ClapTrap (void)
{
	std::cout << "ClapTrap destructor called" << std::endl;
}

ClapTrap &	ClapTrap::operator = (const ClapTrap & clap)
{
	_name = clap._name;
	_hit = clap._hit;
	_energy = clap._energy;
	_attack = clap._attack;
	return *this;
}

void	ClapTrap::attack(const std::string & target)
{
	if (_hit == 0 || _energy == 0)
	{
		std::cout << "ClapTrap " << _name << " cannot attack" << std::endl;
		return;
	}
	std::cout << "ClapTrap " << _name << " attacks " << target
			  << ", causing " << _attack << " points of damage! "
			  << --_energy << " energy points left"
			  << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (_hit == 0)
	{
		std::cout << "ClapTrap " << _name << " is already dead" << std::endl;
		return;
	}
	std::cout << "ClapTrap " << _name
			  << " has been attacked, losing " 
			  << amount << " hit points! ";
	if (amount >= _hit)
	{
		_hit = 0;
		std::cout << "ClapTrap " << _name << " died" << std::endl;
	}
	else
	{
		_hit -= amount;
		std::cout << _hit << " hit points left" << std::endl;
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (_hit == 0 || _energy == 0)
	{
		std::cout << "ClapTrap " << _name << " cannot be repaired" << std::endl;
		return;
	}
	_hit += amount;
	std::cout << "ClapTrap " << _name
			  << " has been repaired, healing "
			  << amount << " hit points! "
			  << --_energy << " energy points left. "
			  << _hit << " hit points left."
			  << std::endl;
}
