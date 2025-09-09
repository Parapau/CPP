#include "../ClapTrap.hpp"

//CONSTRUCTORS

ClapTrap::ClapTrap(void)
{
	this->_name = "Agapito Disousa";
	this->_hitPoints = 10;
	this->_energyPoints = 10;
	this->_attack = 0;
	std::cout << "Default constructor" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
{
	this->_name = name;
	this->_hitPoints = 10;
	this->_energyPoints = 10;
	this->_attack = 0;
	std::cout << "Named constructor" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap &og)
{
	this->_name = og.getName();
	this->_hitPoints = og.getHP();
	this->_energyPoints = og.getEP();
	this->_attack = og.getAttack();
	std::cout << "Copy constructor" << std::endl;
}

//DESTRUCTOR

ClapTrap::~ClapTrap(void)
{
	std::cout << "Destructor called" << std::endl;
}

//FUNCTIONS

void	ClapTrap::attack(const std::string &target)
{
	std::cout << "ClapTrap " << getName() << " attacks " << target
		<< ", causing " << getAttack() << " points of damage."
		<< std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	int		newHealth;

	newHealth = getHP() - amount;
	setHP(newHealth);
	std::cout << "ClapTrap " << getName() << " is hurt for "
		<< amount << " points of damage." << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	int		newHealth;

	newHealth = getHP() + amount;
	setHP(newHealth);
	std::cout << "ClapTrap " << getName() << " is repaired for "
		<< amount << " points of damage." << std::endl;
}

//GETTERS

std::string	ClapTrap::getName(void)
{
	return (this->_name);
}

int	ClapTrap::getHP(void)
{
	return (this->_hitPoints);
}

int	ClapTrap::getEP(void)
{
	return (this->_energyPoints);
}

int	ClapTrap::getAttack(void)
{
	return (this->_attack);
}

//SETTERS

void	ClapTrap::setName(std::string name)
{
	this->_name = name;
}

void	ClapTrap::setHP(int hp)
{
	this->_hitPoints = hp;
}

void	ClapTrap::setEP(int ep)
{
	this->_energyPoints = ep;
}

void	ClapTrap::setAttack(int attack)
{
	this->_attack = attack;
}




