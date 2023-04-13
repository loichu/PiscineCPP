#ifndef ZOMBIE_HPP

# define ZOMBIE_HPP
# include <string>

class Zombie
{
	public:
	Zombie();
	~Zombie();
	Zombie(std::string name);
	void	announce(void);
	void	setName(std::string name);
	private:
	std::string	_name;	
};

Zombie*	zombieHorde(int n, std::string name);
#endif
