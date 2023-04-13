#include "Zombie.hpp"
#include <iostream>

Zombie*	zombieHorde(int n, std::string name)
{
	Zombie	*zombies = new Zombie[n];

	for (int i = 0; i < n; ++i)
	{
		zombies[i] = Zombie(name);
		std::cout << "from assignment loop" << std::endl;
	}
	return (zombies);
}
