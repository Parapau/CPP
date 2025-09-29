#ifndef ICHARACTER_HPP
# define ICHARACTER_HPP

#include <list>
#include <string>
#include <iostream>
#include "AMateria.hpp"

class AMateria;

class ICharacter
{
	public:
		virtual ~ICharacter(void) {}

		virtual std::string const	getName(void) const = 0;

		virtual void				equip(AMateria *m) = 0;
		virtual void				unequip(int i) = 0;
		virtual void				use(int i, ICharacter &target) = 0;
};

#endif
