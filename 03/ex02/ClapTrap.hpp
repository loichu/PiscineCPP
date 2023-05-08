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

	//std::string		getName(void);
	//void			setName(std::string name);

	//unsigned int	getHit(void);
	//void			setHit(unsigned int hit);

	//unsigned int	getEnergy(void);
	//void			setEnergy(unsigned int energy);

	//unsigned int	getAttack(void);
	//void			setAttack(unsigned int attack);

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
