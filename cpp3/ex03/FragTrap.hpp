#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
	public:
		FragTrap(void);
		FragTrap(FragTrap &scav);
		FragTrap(std::string name);
		FragTrap	&operator=(const FragTrap &og);

		void		highFivesGuys();

		~FragTrap();
};



#endif
