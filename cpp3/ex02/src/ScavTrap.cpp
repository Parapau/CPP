#include "../ScavTrap.hpp"

//CONSTRUCTORS

ScavTrap::ScavTrap(void)
{
	setName("Anselmo");
	setHP(100);
	setEP(50);
	setAttack(20);
	std::cout << "Default scav constructor" << std::endl;
}

ScavTrap::ScavTrap(std::string name)
{
	setName(name);
	setHP(100);
	setEP(50);
	setAttack(20);
	std::cout << "Default scav constructor" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap &og): ClapTrap(og)
{
	/*
	setName(og.getName());
	setHP(og.getHP());
	setEP(og.getEP());
	setAttack(og.getAttack());
	*/
	*this = og;
	std::cout << "Copy scav constructor" << std::endl;
}

//DESTRUCTOR

ScavTrap::~ScavTrap(void)
{
	std::cout << "Scav destructor called" << std::endl;
}

//FUNCTIONS

void	ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap " << getName() << " is on gate guard mode." << std::endl;
}

//OVERLOADS

ScavTrap	&ScavTrap::operator=(const ScavTrap &og)
{
	std::cout << "Copy scav assignement operator called" << std::endl;
	setName(og.getName());
	setHP(og.getHP());
	setEP(og.getEP());
	setAttack(og.getAttack());
	return (*this);
}
