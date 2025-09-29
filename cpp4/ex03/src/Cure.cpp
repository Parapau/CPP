#include "../Cure.hpp"

//CONSTRUCTORS

Cure::Cure(void): AMateria("cure")
{
}

Cure::Cure(Cure &og)
{
	*this = og;
}

//DESTRUCTOR

Cure::~Cure(void)
{
}

//OVERLOADS

Cure	&Cure::operator=(Cure &og)
{
	setType(og.getType());
	return (*this);
}

//METHODS

AMateria	*Cure::clone() const
{
	Cure		*ret;

	ret = new Cure;
	return (ret);
}

void		Cure::use(ICharacter &target)
{
	std::cout << ": throws a bunch of ice syringes at " << target.getName()
		<< " that somehow magically heal them."<< std::endl;
}
