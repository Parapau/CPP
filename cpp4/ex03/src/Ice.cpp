#include "../Ice.hpp"

//CONSTRUCTORS

Ice::Ice(void): AMateria("ice")
{
}

Ice::Ice(Ice &og)
{
	*this = og;
}

//DESTRUCTOR

Ice::~Ice(void)
{
	std::cout << "🧊🔨" << std::endl;
}

//OVERLOADS

Ice	&Ice::operator=(Ice &og)
{
	setType(og.getType());
	return (*this);
}

//METHODS

AMateria	*Ice::clone() const
{
	Ice		*ret;

	ret = new Ice;
	return (ret);
}

void		Ice::use(ICharacter &target)
{
	std::cout << ": throws a bunch of ice cubes at " << target.getName()
		<< "." << std::endl;
}
