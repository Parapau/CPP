#ifndef ICE_HPP
# define ICE_HPP

#include "AMateria.hpp"

class Ice: virtual public AMateria
{
	public:
		Ice(void);
		Ice(Ice &og);
		~Ice(void);

		Ice	&operator=(Ice &og);

		AMateria	*clone() const;
		void		use(ICharacter &target);
};

#endif
