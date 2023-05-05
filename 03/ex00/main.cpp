#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap clap1("Thony");
	ClapTrap clap2 = clap1;
	ClapTrap clap3(clap2);
}
