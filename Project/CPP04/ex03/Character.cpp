#include "Character.hpp"

Character::Character(void): _name(NULL)
{
	for (int i = 0; i < 4; i++)
		inventory[i] = NULL;
	std::cout << "Character Constructor Called" << std::endl;
}

Character::Character(const std::string &name): _name(name)
{
	for (int i = 0; i < 4; i++)
		inventory[i] = NULL;
	std::cout << "Character Constructor Called" << std::endl;
}

Character::Character(const Character &a)
{
	_name = a._name;
	for (int i = 0; i < 4; i++)
		inventory[i] = a.inventory[i]->clone();
	std::cout << "Character Copy Constructor Called" << std::endl;
}

Character &Character::operator = (const Character &a)
{
	_name = a._name;
	for (int i = 0; i < 4; i++)
	{
		if (inventory[i])
			delete (inventory[i]);
	}
	for (int i = 0; i < 4; i++)
		inventory[i] = a.inventory[i]->clone();
	return (*this);
}

Character::~Character(void)
{
	for (int i = 0; i < 4; i++)
	{
		if (inventory[i])
			delete (inventory[i]);
	}
	std::cout << "Character Destructor Called" << std::endl;
}

std::string const &Character::getName(void) const
{
	return (_name);
}

void	Character::equip(AMateria *m)
{
	int	i;

	i = 0;
	while (inventory[i] && i < 4)
		i++;
	if (i >= 4)
		return ;
	inventory[i] = m;
}

//Careful on using it, you may lose an address :)
void	Character::unequip(int idx)
{
	inventory[idx] = NULL;
}

void	Character::use(int idx, ICharacter &target)
{
	if ((idx < 0 || idx > 3) || !inventory[idx])
	{
		std::cerr << _name << " cannot use item " << idx << std::endl;
		return ;
	}
	inventory[idx]->use(target);
}
