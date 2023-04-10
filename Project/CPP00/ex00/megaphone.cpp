#include <iostream>

int	main(int ac, char *av[])
{
	std::string	str;
	int		i;

	i = 1;
	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	while (i < ac)
	{
		str = av[i];
		for (std::string::iterator it=str.begin(); it!=str.end(); ++it)
			std::cout << (char) toupper(*it);
		i++;
	}
	std::cout << std::endl;
}
