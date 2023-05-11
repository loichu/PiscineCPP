#ifndef CLAPTRAP
# define CLAPTRAP
# include <string>
# include <iostream>

class ClapTrap
{
	public:
	ClapTrap();
	ClapTrap(const ClapTrap & clap);
	ClapTrap(std::string name);

	~ClapTrap(void);

	ClapTrap	&operator = (const ClapTrap & clap);

	void	attack(const std::string & target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);

	protected:
	std::string		_name;
	unsigned int	_hit;
	unsigned int	_energy;
	unsigned int	_attack;
};

#endif
