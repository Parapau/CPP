#include "../ScavTrap.hpp"
#include "../FragTrap.hpp"
#include "../DiamondTrap.hpp"

void	preDiamond(void)
{
	ClapTrap	a;
	ClapTrap	b("Pau");
	ClapTrap	c(b);
	ScavTrap	d;
	ScavTrap	e("Pep");
	FragTrap	f;
	FragTrap	g("Joaquim");

	b.attack("pepe");
	c.takeDamage(5);
	a.beRepaired(4);
	d.attack("Ildefons");
	e.takeDamage(3);
	e.guardGate();
	e.guardGate();
	g.highFivesGuys();
}

void	postDiamond(void)
{
	DiamondTrap	h;
	DiamondTrap	i("Anna Maria");

	i.guardGate();
	i.highFivesGuys();
	i.guardGate();
	i.attack("Pere Botero");
	i.whoAmI();
}

int	main(void)
{
	preDiamond();
	std::cout << "I JUST FOUND DIAMODS!!!!!!!!" << std::endl;
	postDiamond();
}
