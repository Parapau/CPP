#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public:
		ScavTrap(void);
		ScavTrap(ScavTrap &scav);
		ScavTrap(std::string name);
		ScavTrap	&operator=(const ScavTrap &og);

		void		guardGate();

		~ScavTrap();
};



#endif
