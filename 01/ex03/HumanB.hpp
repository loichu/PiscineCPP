#ifndef HUMAN_B_HPP
# define HUMAN_B_HPP

#include <string>
#include <iostream>
#include "Weapon.hpp"

class HumanB
{
	public:
	HumanB(std::string);
	void	setWeapon(Weapon&);
	void	attack();

	private:
	std::string	_name;
	Weapon		*_weapon;
};

#endif
