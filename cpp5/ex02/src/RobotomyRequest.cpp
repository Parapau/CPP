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
	(void) bar;
	std::cout << "BRRRRRRRRRRRRRRRRRR WIRRRRRRRRRRRRRRRRRRRRRRRRR beep boop seeep CRAACK BRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRR" << std::endl;
	srand(time(0));
	if (rand() % 2 == 0)
	{
		std::cout << "Succes!!" << std::endl << "The robot " << getTarget() << " has been succesfully robotomized and is now just a shadow of their former self"
		<< std::endl << "they will now spend the rest of their days as an empty shell of a robot not being able to comprehend what has happened but knowing for certain that something has been robbed from them and they will never get it back andthey won't ever be the same without it"
		<< std::endl << "Congratulations! 😃👍" << std::endl;
	}
	else
	{
		std::cout << "Failure!!" << std::endl << "The robotomy on " << getTarget() << " has failed just leaving a major scar on their forehead" << std::endl
		<< "They will now spend the rest of their days happy and free and live a full life eventually getting over the traumatizing event that was their attempted robotomy"
		<< std:: endl << "Try harder next time 😡" << std::endl;
	}
}
