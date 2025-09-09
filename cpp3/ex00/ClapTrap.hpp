#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <string>
#include <iostream>

class ClapTrap
{
	private:
		std::string		_name;
		int				_hitPoints;
		int				_energyPoints;
		int				_attack;
	public:
		ClapTrap(void);
		ClapTrap(ClapTrap &clap);
		ClapTrap(std::string name);
		ClapTrap	&operator=(const ClapTrap &og);

		void		attack(const std::string &target);
		void		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);

		std::string		getName(void);
		int				getHP(void);
		int				getEP(void);
		int				getAttack(void);
		void			setName(std::string name);
		void			setHP(int HP);
		void			setEP(int EP);
		void			setAttack(int attack);
		~ClapTrap(void);
};

#endif
