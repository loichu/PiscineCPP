#ifndef FRAGTRAP 
# define FRAGTRAP
# include "ClapTrap.hpp"
# include <string>
# include <iostream>

class FragTrap : public ClapTrap
{
	public:
	FragTrap();
	FragTrap(const FragTrap & scav);
	FragTrap(std::string name);

	~FragTrap(void);

	void	highFivesGuys(void);
};

#endif
