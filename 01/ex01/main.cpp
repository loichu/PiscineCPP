#include "Zombie.hpp"
#include <iostream>

void	test_horde(int n, std::string name)
{
	Zombie* zombies = zombieHorde(n, name);
	std::cout << "Horde instanciated" << std::endl;
	for (int i = 0; i < n; ++i)
	{
		zombies[i].announce();
		//delete zombies[i];
	}
	// This doesn't work
	delete[] zombies;
}

int	main(void)
{
	test_horde(10, "Toto1");
	//test_horde(5, "Tata2");
	//test_horde(-1, "Tutu3");
	//test_horde(10000, "Titi4");
}
