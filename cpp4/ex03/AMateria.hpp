#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include <string>
#include <iostream>
#include "ICharacter.hpp"

class ICharacter;

class AMateria
{
	protected:
		std::string		_type;
		std::string		_usage;
	public:
		AMateria(void);
		AMateria(AMateria &og);
		AMateria(std::string const type);
		virtual ~AMateria(void);

		AMateria	&operator=(AMateria &og);
		
		std::string			getType();
		std::string			getUsage();

		void				setType(std::string type);
		void				setUsage(std::string usage);

		virtual AMateria	*clone() const = 0;
		virtual void		use(ICharacter &target);
};

#endif
