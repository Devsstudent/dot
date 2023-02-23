#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
#include <iostream>
#include "Zombie.hpp"

class	Zombie {
	public :
		Zombie();
		~Zombie();
		void	set_name( std::string name );
		void	announce( void );
	private :
		std::string	name;
};

void	delete_horde( Zombie *horde);
Zombie*	zombieHorde( int N, std::string name);

#endif
