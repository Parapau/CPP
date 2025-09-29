#include "../MateriaSource.hpp"

//CONSTRUCTORS

MateriaSource::MateriaSource(void)
{
	for (int i = 0; i < 4; i++)
		setMaterI(1, 0);
}

MateriaSource::MateriaSource(MateriaSource &og)
{
	AMateria	*mat;

	for (int i = 0; i < 4; i++)
	{
		mat = og.getMaterI(i);
		if (mat != 0)
			setMaterI(i, mat->clone());
		else
			setMaterI(i, 0);
	}
}

//DESTRUCTOR

MateriaSource::~MateriaSource(void)
{
	AMateria	*mat;

	std::cout << "My source is that i made it the fuck up" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		mat = getMaterI(i);
		if (mat != 0)
			delete mat;
	}
}

//OVERLOADS

MateriaSource	&MateriaSource::operator=(MateriaSource &og)
{
	AMateria	*mat;

	for (int i = 0; i < 4; i++)
	{
		mat = og.getMaterI(i);
		if (mat != 0)
			setMaterI(i, mat->clone());
		else
			setMaterI(i, 0);
	}
	return (*this);
}

//GETTERS

AMateria	*MateriaSource::getMaterI(int i)
{
	if (i < 0 || i > 3)
		return (0);
	return (this->_mater[i]);
}

//SETTERS

void	MateriaSource::setMaterI(int i, AMateria *item)
{
	if (i < 0 || i > 3)
		return ;
	this->_mater[i] = item;
}

//METHODS

void	MateriaSource::learnMateria(AMateria *m)
{
	int		i;

	i = 0;
	if (m == 0)
		return ;
	while (i < 4)
	{
		if (getMaterI(i) == 0)
		{
			setMaterI(i, m);
			return;
		}
		i++;
	}
	delete m;
	std::cout << "I can't learn more than than 4 things but that's alright because i have high self esteem and can play the trombone very good :)" << std::endl;
}

AMateria	*MateriaSource::createMateria(std::string const &type)
{
	int		i;
	AMateria	*mat;

	i = 0;
	while (i < 4)
	{
		mat = getMaterI(i);
		if (mat->getType() == type)
			return (mat->clone());
		i++;
	}
	return (0);
}
