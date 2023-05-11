#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap clap1("Rico l'asticot");
	ClapTrap clap2;
	ClapTrap clap3(clap1);
	ClapTrap clap4(clap2);

	clap1.attack("the cops");
	clap2.attack("the gouvernement");
	clap3.attack("Bill Gates");
	clap4.attack("Nestlé");
	clap1.attack("Vladimir Putin");
	clap1.attack("himself");
	clap1.takeDamage(0);
	clap1.attack("an aligator");
	clap1.takeDamage(5);
	clap1.beRepaired(5);
	clap1.takeDamage(9);
	clap1.beRepaired(5);
	clap1.takeDamage(3);
	clap1.beRepaired(3);
	clap1.beRepaired(3);
	clap1.attack("an Apple fanboy");
	clap1.attack("an Apple fanboy");
	clap1.attack("an Apple fanboy");
	clap1.beRepaired(3);
	clap1.takeDamage(10);
	clap1.takeDamage(10);
	clap1.beRepaired(3);
	clap1.attack("a random guy");
	clap2.attack("the gouvernement");
	clap3.attack("Bill Gates");
	clap4.attack("Nestlé");
}
