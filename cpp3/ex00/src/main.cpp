#include "../ClapTrap.hpp"

int	main(void)
{
	ClapTrap	a;
	ClapTrap	b("Pau");
	ClapTrap	c(b);

	b.attack("pepe");
	c.takeDamage(5);
	a.beRepaired(4);
}
