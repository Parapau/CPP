#include "../Character.hpp"

std::list<AMateria *> Character::_floor;

//CONSTRUCTORS

Character::Character(void)
{
	for (int i = 0; i < 4; i++)
		setInvSlot(0, 1);
}

Character::Character(Character &og)
{
	AMateria	*mat;

	setName(og.getName());
	for (int i = 0; i < 4; i++)
	{
		mat = og.getInvSlot(i);
		if (mat != 0)
			setInvSlot(mat->clone(), i);
		else
			setInvSlot(0, i);
	}
}

Character::Character(std::string name)
{
	setName(name);
	for (int i = 0; i < 4; i++)
		setInvSlot(0, 1);
}

//DESTRUCTOR

Character::~Character(void)
{
	std::cout << getName() << " is kil" << std::endl;
	for (int i = 0; i < 4; i++)
		unequip(i);
}

//OVERLOADS

Character	&Character::operator=(Character &og)
{
	AMateria	*mat;

	setName(og.getName());
	for (int i = 0; i < 4; i++)
	{
		mat = og.getInvSlot(i);
		if (mat != 0)
			setInvSlot(mat->clone(), i);
		else
			setInvSlot(0, i);
	}
	return (*this);
}

//GETTERS

std::string const	Character::getName(void) const
{
	return (this->_name);
}

AMateria	*Character::getInvSlot(int i)
{
	if (i < 0 || i > 3)
		return (0);
	return (this->_inventory[i]);
}

//SETTERS

void	Character::setName(std::string name)
{
	this->_name = name;
}

void	Character::setInvSlot(AMateria *item, int i)
{
	if (i < 0 || i > 3)
		return ;
	this->_inventory[i] = item;
}

//METHODS

void	Character::equip(AMateria *m)
{
	int		i;

	i = 0;
	if (m == 0)
		return ;
	while (i < 4)
	{
		if (getInvSlot(i) == 0)
		{
			setInvSlot(m, i);
			return;
		}
		i++;
	}
	std::cout << "Oops, i dropped that " << m->getType()
		<< " it appears my hands are full and i can't hold anything else" << std::endl;
	drop(m);
}

void	Character::unequip(int i)
{
	AMateria	*mat;

	mat = getInvSlot(i);
	if (mat != 0)
	{
		setInvSlot(0, i);
		drop(mat);
	}
}

void	Character::use(int i, ICharacter &target)
{
	AMateria	*mat;

	mat = getInvSlot(i);
	if (mat != 0)
	{
		std::cout << getName();
		mat->use(target);
		return ;
	}
	std::cout << "I'm not a magician, i cannot use something i don't have" << std::endl;

}

void	Character::sweepFloor(void)
{
	std::cout << "*whistling while sweeping the floor*" << std::endl;
	for (std::list<AMateria *>::iterator i = Character::_floor.begin();
			i != Character::_floor.end(); ++i)
		delete *i;
}

void	Character::drop(AMateria *m)
{
	Character::_floor.push_back(m);
}
