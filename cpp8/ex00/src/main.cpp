#include "../easyfind.hpp"

int main(void)
{
	std::string		str;

	str = "putatotato";
	std::cout << easyfind(str, 'o') << std::endl;
	try
	{
		std::cout << easyfind(str, 'l') << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	};
}
