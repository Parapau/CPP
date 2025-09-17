#include "../Harl.hpp"

Harl::Harl(void)
{
}

Harl::~Harl(void)
{
}

void	Harl::debug(void)
{
	std::cout << "I want to sleep" << std::endl;
}

void	Harl::info(void)
{
	std::cout << "Like fr i slept like hours last night" << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "I'm warning you i may fall asleep on the keyboard rn" << std::endl;
}

void	Harl::error(void)
{
	std::cout << " vhuy77777j bbbuy7yhujikoij juh7my777777777777777777777777777777777777777777777777777777777777777770piouij7bmhy0p" << std::endl;
}

void	Harl::complain(std::string level)
{
	std::string		levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void			(Harl::*complaints[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	int				i;

	i = 0;
	while (i < 4)
	{
		if (level == levels[i])
		{
			(this->*complaints[i])();
			return ;
		}
		i++;
	}
	std::cout << "am dead" << std::endl;
	return ;
}
