#include "Zombie.hpp"

int	main(void)
{
	Zombie	*horde;
	int		horde_size;
	int		i;

	horde_size = 10;
	horde = zombieHorde(horde_size, "Broo");
	for (i = 0; i < horde_size; i++)
		horde[i].announce();
	delete_horde(horde);
}
