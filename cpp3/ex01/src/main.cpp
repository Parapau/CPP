#include "../ScavTrap.hpp"

int	main(void)
{
	ClapTrap	a;
	ClapTrap	b("Pau");
	ClapTrap	c(b);
	ScavTrap	d;
	ScavTrap	e("Pep");

	b.attack("pepe");
	c.takeDamage(5);
	a.beRepaired(4);
	d.attack("Ildefons");
	e.takeDamage(3);
	e.guardGate();
	e.guardGate();
}
