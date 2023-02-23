#include "Weapon.hpp"

Weapon::Weapon(std::string type): type(type)
{
	std::cout << "A weapon as "<< this->type << " been contructed" << std::endl;
}

Weapon::~Weapon()
{
	std::cout << "A weapon " << this->type << " as been destroyed" << std::endl;
}

void	Weapon::setType(std::string type)
{
	this->type = type;
}

std::string	Weapon::getType(void)
{
	return (this->type);
}

