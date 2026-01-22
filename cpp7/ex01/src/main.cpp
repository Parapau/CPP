#include "../iter.hpp"
#include <string>
#include <iostream>

void	pront(std::string str)
{
	std::cout << str << std::endl;
}

void	isNumber(int num)
{
	int num2;

	num2 = num;
	if (num == num2)
		std::cout << "yes, " << num << " is indeed a number" << std::endl << "this function is stupid" << std::endl;
	else
		std::cout << "no numbers here, move along" << std::endl;
}

int main(void)
{
	std::string		array1[6] = {"les", "patates", "fregides", "estan", "molt", "bones"};
	int				array2[3] = {4, 2, 0};

	iter(array1, 6, pront);
	iter(array2, 3, isNumber);
}
