#include "ScavTrap.hpp"

int main(void)
{
	ScavTrap scav1("René");

	scav1.attack("Rico l'asticot");
	scav1.guardGate();
	scav1.takeDamage(99);
	scav1.takeDamage(1);
	scav1.guardGate();
}
