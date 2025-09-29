#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include <string>
#include "IMateriaSource.hpp"
#include "AMateria.hpp"

class MateriaSource: public IMateriaSource
{
	protected:
		AMateria	*_mater[4];
	public:
		MateriaSource(void);
		MateriaSource(MateriaSource &og);
		~MateriaSource(void);

		MateriaSource	&operator=(MateriaSource &og);

		AMateria	*getMaterI(int i);

		void		setMaterI(int i, AMateria *mat);

		void learnMateria(AMateria *mat);
		AMateria* createMateria(std::string const &type);
};

#endif
