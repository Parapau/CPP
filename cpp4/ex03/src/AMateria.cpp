#include "../AMateria.hpp"

//CONSTRUCTORS

AMateria::AMateria(void)
{
}

AMateria::AMateria(AMateria &og)
{
	*this = og;
}

AMateria::AMateria(std::string const type)
{
	this->_type = type;
}

//DESTRUCTOR

AMateria::~AMateria(void)
{
}

//OVERLOADS

AMateria	&AMateria::operator=(AMateria &og)
{
	setType(og.getType());
	return (*this);
}

//GETTERS

std::string	AMateria::getType(void)
{
	return (this->_type);
}

//SETTERS

void	AMateria::setType(std::string type)
{
	this->_type = type;
}

//METHODS

void	AMateria::use(ICharacter &target)
{
	std::cout << "Se que cada qual tiene su aficion, yo cazo para elaborar un verstuario resulton." << std::endl
		<< "Y lo ven, ya lo ven. EL gorila sienta bien. Mi chaqueta no se agrieta es de autentica gineta. " << std::endl
		<< "Este es mi siames. Imagen doy de marques. En la casa me engalano con estilo africano. " << std::endl
		<< "Un calzon de bison. Un jersey caparazon. Oportuno fez perruno en la sieeen. Abrigos de plumon, los hay de quita y pon. ;" << std::endl
		<< "Ya lo ven, ya lo ven, ya lo veeeeen" << std::endl
		<< "Mooocasines saltarines con la piel de dos mastines. Los cachorros para esmoquin van feteeen." << std::endl
		<< "Pues bien preparalos." << std::endl << "Y casi salen dos." << std::endl
		<< "Ya lo ven, ya lo veen, oh si yo lo se muy bieeeeeeeeeeeeeeeen" << std::endl
		<< "Me encanta esta prenda" << std::endl
		<< "Ya me he dado cuenta" << std::endl
		<< "Oohhh, esta pensando hacerse un esmoquin con los cachorros!" << std::endl
		<< "Nanana, nanana, nananana." << std::endl
		<< target.getName() << std::endl;
}
