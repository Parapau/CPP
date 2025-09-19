#include "../FragTrap.hpp"

//CONSTRUCTORS

FragTrap::FragTrap(void)
{
	setName(ClapTrap::_name);
	setHP(100);
	setEP(50);
	setAttack(20);
	std::cout << "Default frag constructor" << std::endl;
}

FragTrap::FragTrap(std::string name)
{
	setName(name);
	setHP(100);
	setEP(50);
	setAttack(20);
	std::cout << "Default frag constructor" << std::endl;
}

FragTrap::FragTrap(FragTrap &og): ClapTrap(og)
{
	/*
	setName(og.getName());
	setHP(og.getHP());
	setEP(og.getEP());
	setAttack(og.getAttack());
	*/
	*this = og;
	std::cout << "Copy frag constructor" << std::endl;
}

//DESTRUCTOR

FragTrap::~FragTrap(void)
{
	std::cout << "Frag destructor called" << std::endl;
}

//FUNCTIONS

void	FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << getName() << " wants to high-five you :)" << std::endl;
}

//OVERLOADS

FragTrap	&FragTrap::operator=(const FragTrap &og)
{
	std::cout << "Copy Frag assignement operator called" << std::endl;
	setName(og.getName());
	setHP(og.getHP());
	setEP(og.getEP());
	setAttack(og.getAttack());
	return (*this);
}
