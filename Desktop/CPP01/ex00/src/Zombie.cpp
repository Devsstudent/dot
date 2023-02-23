#include "Zombie.hpp"

Zombie::Zombie()
{
	std::cout << "A zombie as been contructed" << std::endl;
}

Zombie::Zombie( std::string name)
{
	this->name = name;
	std::cout << "A zombie named " << this->name << "as been contructed" << std::endl;
}

Zombie::~Zombie()
{
	std::cout << this->name << " Destroyed" << std::endl;
}

void	Zombie::announce(void)
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
