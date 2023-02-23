#include "Zombie.hpp"

Zombie*	zombieHorde( int N, std::string name)
{
	Zombie	*horde;
	int		i;

	i = -1;
	horde = new Zombie[N];
	while (++i < N)
		horde[i].set_name(name);
	return (horde);
}

void	delete_horde( Zombie *horde)
{
	delete[] horde;
}
