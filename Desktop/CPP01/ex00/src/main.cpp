#include "Zombie.hpp"

int	main(void)
{
	Zombie	*buff;

	randomChump( "test" );
	buff = newZombie( "Bruh" );
	buff->announce();
	delete buff;
}
