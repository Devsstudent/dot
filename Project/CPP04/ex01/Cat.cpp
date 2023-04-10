#include "Cat.hpp"

Cat::Cat(void)
{
	setType("Cat");
	cerveaux = new Brain();
	std::cout << "A cat has been constructed" << std::endl;
}

Cat::Cat(const Cat &a)
{
	if (this != &a)
	{
		setType(a.getType());
		cerveaux = new Brain(*a.cerveaux);
	}
	std::cout << "A cat has been constructed by copy" << std::endl;
}

Cat	&Cat::operator = (const Cat &a)
{
	setType(a.getType());
	delete cerveaux;
	cerveaux = new Brain(*a.cerveaux);
	std::cout << "Overload operator egal called" << std::endl;
	return (*this);
}

Cat::~Cat(void)
{
	std::cout << "A cat has been destroyed" << std::endl;
	delete cerveaux;
}

Brain	*Cat::getBrain(void) const
{
	return (cerveaux);
}

void	Cat::makeSound(void) const
{
	std::cout << "Miaouu.." << std::endl;
}
