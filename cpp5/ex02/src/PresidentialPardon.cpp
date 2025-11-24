#include "../PresidentialPardon.hpp"

//CONSTRUCTORS

PresidentialPardon::PresidentialPardon(void):
	Form("PresidentialPardon", 25, 5), _target("PereBotero")
{
}

PresidentialPardon::PresidentialPardon(std::string target):
	Form("PresidentialPardon", 25, 5), _target(target)
{
}

PresidentialPardon	&PresidentialPardon::operator=(PresidentialPardon &og):
	Form(og)
{
	this->target = og.target;
	return (*this);
}

//OVERLOAD



//DESTRUCTORS

PresidentialPardon::~PresidentialPardon(void)
{
}

//GETTERS

std::string		PresidentialPardon::getTarget(void)
{
	return (this->_target);
}

//SETTERS

void	PresidentialPardon::setTarget(std::string target)
{
	this->_target = target;
}

//METHODS

void	PresidentialPardon::execute(Bureaucrat &bar)
{
	std::cout << bar.getName() << " has convinced president Robocop to pardon " <<
		getTarget() << " for their multiple counts of terrorism and mail fraud"
		<< std::endl;
}
