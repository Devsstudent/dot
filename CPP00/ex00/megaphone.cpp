#include <iostream>

using namespace std;

int	main(int ac, char *av[])
{
	string	str;
	int		i;

	i = 1;
	if (ac == 1)
		cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	while (i < ac)
	{
		str = av[i];
		for (string::iterator it=str.begin(); it!=str.end(); ++it)
			cout << (char) toupper(*it);
		i++;
	}
	cout << endl;
}
