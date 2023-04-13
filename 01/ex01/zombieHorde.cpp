#include "Zombie.hpp"
#include <iostream>

Zombie*	zombieHorde(int n, std::string name)
{
	Zombie	*zombies = new Zombie[n > 0 ? n : 0];

	for (int i = 0; i < n; ++i)
		zombies[i].setName(name);

	return (zombies);
}
