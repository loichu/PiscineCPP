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
			  << ", causing " << _attack << " points of damage!"
			  << std::endl;
}
