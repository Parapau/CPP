#ifndef CURE_HPP
# define CURE_HPP

#include "AMateria.hpp"

class Cure: virtual public AMateria
{
	public:
		Cure(void);
		Cure(Cure &og);
		~Cure(void);

		Cure	&operator=(Cure &og);

		AMateria	*clone() const;
		void		use(ICharacter &target);
};

#endif
