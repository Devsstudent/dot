#include "WrongCat.hpp"

WrongCat::WrongCat(void)
{
	setType("WrongCat");
	std::cout << "A wrong cat has been constructed" << std::endl;
}

WrongCat::WrongCat(const WrongCat &a)
{
	setType(a.getType());
	std::cout << "A wrong cat has been constructed by copy" << std::endl;
}

WrongCat	&WrongCat::operator = (const WrongCat &a)
{
	setType(a.getType());
	std::cout << "Overload operator egal called" << std::endl;
	return (*this);
}

WrongCat::~WrongCat(void)
{
	std::cout << "A wrong cat has been destroyed" << std::endl;
}

void	WrongCat::makeSound(void) const
{
	std::cout << "Miaouu.." << std::endl;
}
