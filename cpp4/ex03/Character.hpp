#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include <list>
#include <string>
#include <iostream>
#include "ICharacter.hpp"

class Character: public ICharacter
{
	protected:
		std::string						_name;
		AMateria						*_inventory[4];
		static std::list<AMateria *>	_floor;
	public:
		Character(void);
		Character(Character &og);
		Character(std::string name);
		~Character(void);

		Character		&operator=(Character &og);

		std::string const	getName(void) const;
		AMateria			*getInvSlot(int i);

		void				setName(std::string name);
		void				setInvSlot(AMateria *item, int i);

		void				equip(AMateria *m);
		void				unequip(int i);
		void				use(int i, ICharacter &target);
		static void			sweepFloor(void);
		static void			drop(AMateria *m);
};

#endif
