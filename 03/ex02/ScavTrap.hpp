#ifndef SCAVTRAP 
# define SCAVTRAP
# include "ClapTrap.hpp"
# include <string>
# include <iostream>

class ScavTrap : public ClapTrap
{
	public:
	ScavTrap();
	ScavTrap(const ScavTrap & scav);
	ScavTrap(std::string name);

	~ScavTrap(void);

	void	attack(const std::string & target);
	void	guardGate(void);
};

#endif
