#include "Zombie.hpp"

int	main(void)
{
	Zombie*	toto = newZombie("Toto");
	toto->announce();
	randomChump("Tata");
	delete toto;
}
