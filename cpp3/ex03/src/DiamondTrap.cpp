#include "../DiamondTrap.hpp"

//CONSTRUCTORS

DiamondTrap::DiamondTrap(void): ClapTrap("Agapito Disousa_clap_name"), ScavTrap(), FragTrap()
{
	this->_name = "Agapito Disousa";
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attack = FragTrap::_attack;
	std::cout << "DiamondTrap constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name): ClapTrap(name + "_clap_name"), ScavTrap(), FragTrap()
{
	this->_name = name;
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attack = FragTrap::_attack;
	std::cout << "DiamondTrap named constructor called" << name  << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap &og)
{
	*this = og;
	std::cout << "DiamondTrap copy constructor called" << std::endl;
}

//OVERLOADS

DiamondTrap	&DiamondTrap::operator=(const DiamondTrap &og)
{
	std::cout << "Copy Frag assignement operator called" << std::endl;
	setName(og.getName());
	setHP(og.getHP());
	setEP(og.getEP());
	setAttack(og.getAttack());
	return (*this);
	std::cout << "DiamondTrap copy assignement called" << std::endl;
}

//DESTRUCTORS

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap destructor called" << std::endl;
}

//METHODS

void	DiamondTrap::attack(const std::string target)
{
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI(void)
{
	std::cout << "My diamond name is " << getName()
		<< " but when i want applause i go by " << ClapTrap::_name << std::endl;
}
