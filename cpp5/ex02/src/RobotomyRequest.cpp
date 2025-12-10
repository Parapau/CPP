#include "../RobotomyRequest.hpp"

//CONSTRUCTORS

RobotomyRequest::RobotomyRequest(void):
	Form("RobotomyRequest", 25, 5), _target("Doraemon")
{
}

RobotomyRequest::RobotomyRequest(std::string target):
	Form("RobotomyRequest", 25, 5), _target(target)
{
}

//OVERLOAD

RobotomyRequest	&RobotomyRequest::operator=(RobotomyRequest &og)
{
	this->_target = og._target;
	return (*this);
}

//DESTRUCTORS

RobotomyRequest::~RobotomyRequest(void)
{
}

//GETTERS

std::string		RobotomyRequest::getTarget(void)
{
	return (this->_target);
}

//SETTERS

void	RobotomyRequest::setTarget(std::string target)
{
	this->_target = target;
}

//METHODS

void	RobotomyRequest::carryOut(Bureaucrat &bar)
{
	std::cout << bar.getName() << " stge trist i dessolador que esta al portatil :(" <<
		getTarget() << std::endl;
}
