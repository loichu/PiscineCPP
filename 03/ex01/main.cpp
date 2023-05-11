#include "ScavTrap.hpp"

int main(void)
{
	ScavTrap scavEmpty;
	ScavTrap scav1("René");
	ScavTrap scav2(scav1);

	scav1.attack("Rico l'asticot");
	scav1.guardGate();
	scav1.takeDamage(99);
	scav1.takeDamage(1);
	scav1.guardGate();
}
