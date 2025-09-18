#include "../ClapTrap.hpp"

//CONSTRUCTORS

ClapTrap::ClapTrap(void)
{
	this->_name = "Agapito Disousa";
	this->_hitPoints = 10;
	this->_energyPoints = 10;
	this->_attack = 0;
	std::cout << "Default clap constructor" << std::endl;
}

ClapTrap::ClapTrap(const std::string name)
{
	this->_name = name;
	this->_hitPoints = 10;
	this->_energyPoints = 10;
	this->_attack = 0;
	std::cout << "Named clap constructor" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &og)
{
	this->_name = og.getName();
	this->_hitPoints = og.getHP();
	this->_energyPoints = og.getEP();
	this->_attack = og.getAttack();
	std::cout << "Copy clap constructor" << std::endl;
}

//DESTRUCTOR

ClapTrap::~ClapTrap(void)
{
	std::cout << "Clap destructor called" << std::endl;
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

std::string	ClapTrap::getName(void) const
{
	return (this->_name);
}

int	ClapTrap::getHP(void) const
{
	return (this->_hitPoints);
}

int	ClapTrap::getEP(void) const
{
	return (this->_energyPoints);
}

int	ClapTrap::getAttack(void) const
{
	return (this->_attack);
}

//SETTERS

void	ClapTrap::setName(const std::string name)
{
	this->_name = name;
}

void	ClapTrap::setHP(const int hp)
{
	this->_hitPoints = hp;
}

void	ClapTrap::setEP(const int ep)
{
	this->_energyPoints = ep;
}

void	ClapTrap::setAttack(const int attack)
{
	this->_attack = attack;
}

//OVERLOADS

ClapTrap	&ClapTrap::operator=(const ClapTrap &og)
{
	std::cout << "Copy clap assignement operator called" << std::endl;
	setName(og.getName());
	setHP(og.getHP());
	setEP(og.getEP());
	setAttack(og.getAttack());
	return (*this);
}
