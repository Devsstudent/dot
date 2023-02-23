#include "HumanB.hpp"

HumanB::HumanB(std::string name):weapon(NULL), name(name)
{
	std::cout << "HumanB " << name <<  " contructed" << std::endl;
}

HumanB::~HumanB()
{
	std::cout << "HumanB " << name << " destroyed" << std::endl;
}

std::string	HumanB::get_name(void)
{
	return (name);
}

Weapon	*HumanB::get_weapon(void)
{
	return (weapon);
}

void	HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}

void	HumanB::attack(void)
{
	std::cout << get_name() << "attacks with their " << get_weapon()->getType() << std::endl;
}
