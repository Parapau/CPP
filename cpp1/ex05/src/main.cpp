#include "../Harl.hpp"

int	main(void)
{
	Harl	harl;

	harl = Harl();
	harl.complain("DEBUG");
	harl.complain("INFO");
	harl.complain("WARNING");
	harl.complain("ERROR");
	harl.complain("DED");
}
