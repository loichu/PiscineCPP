#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
	ScavTrap scav1("René");
	FragTrap frag1("Jo");

	scav1.attack("Rico l'asticot");
	scav1.guardGate();
	scav1.takeDamage(99);
	scav1.takeDamage(1);
	scav1.guardGate();

	frag1.attack("Rico l'asticot");
	frag1.highFivesGuys();
	frag1.takeDamage(99);
	frag1.takeDamage(1);
	frag1.highFivesGuys();
}
