#include <stdio.h>
#include <ctype.h>
#include <iostream>

void	print_toupper(char *str)
{
	int		i;
	
	i = 0;
	while (str[i])
	{
		cout << (toupper(str[i]));
		i++;
	}
}

int main(int argc, char **argv)
{
	int		i;
	
	i = 1;
	if (argc == 1)
	{
		cout << * LOUD AND UNBEARABLE FEEDBACK NOISE *
		return (0);
	}
	while (argv[i] != 0)
	{
		cout << print_toupper(argv[i]);
		i++;
	}
}