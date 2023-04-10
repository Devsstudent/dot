#include "Cat.hpp"

Cat::Cat(void)
{
	setType("Cat");
	std::cout << "A cat has been constructed" << std::endl;
}

Cat::Cat(const Cat &a)
{
	setType(a.getType());
	std::cout << "A cat has been constructed by copy" << std::endl;
}

Cat	&Cat::operator = (const Cat &a)
{
	setType(a.getType());
	std::cout << "Overload operator egal called" << std::endl;
	return (*this);
}

Cat::~Cat(void)
{
	std::cout << "A cat has been destroyed" << std::endl;
}

void	Cat::makeSound(void) const
{
	std::cout << "Miaouu.." << std::endl;
}
