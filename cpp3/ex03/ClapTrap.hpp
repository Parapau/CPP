#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <string>
#include <iostream>

class ClapTrap
{
	protected:
		std::string		_name;
		int				_hitPoints;
		int				_energyPoints;
		int				_attack;
	public:
		ClapTrap(void);
		ClapTrap(const ClapTrap &clap);
		ClapTrap(const std::string name);
		ClapTrap	&operator=(const ClapTrap &og);

		void				attack(const std::string &target);
		void				takeDamage(unsigned int amount);
		void				beRepaired(unsigned int amount);

		std::string	getName(void) const;
		int			getHP(void) const;
		int			getEP(void) const;
		int			getAttack(void) const;
		void				setName(const std::string name);
		void				setHP(const int HP);
		void				setEP(const int EP);
		void				setAttack(const int attack);

		~ClapTrap(void);
};

#endif
