#include "../DiamondTrap.hpp"

//CONSTRUCTORS

DiamondTrap::DiamondTrap(void): ClapTrap("Agapito Disousa_clap_name"), ScavTrap(), FragTrap()
{
	this->_name = "Agapito Disousa";
	t
}

DiamondTrap::DiamondTrap(std::string name): ClapTrap(name + "_clap_name"), ScavTrap(), FragTrap()
{
	this->_name = name;
}

DiamondTrap::~DiamondTrap(void)
{
}
