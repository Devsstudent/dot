#include "Harl.hpp"

int	main(int ac, char **av)
{
	Harl	rageux;
	if (ac < 2 || ac > 2)
	{
		std::cout << "Not valid arguments value" << std::endl;
		return (1);
	}
	rageux.complain(av[1]);
}
