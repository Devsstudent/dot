#include "Dog.hpp"

Dog::Dog(void)
{
	setType("Dog");
	std::cout << "A dog has been constructed" << std::endl;
}

Dog::Dog(const Dog &a)
{
	setType(a.getType());
	std::cout << "A dog has been constructed by copy" << std::endl;
}

Dog	&Dog::operator = (const Dog &a)
{
	setType(a.getType());
	std::cout << "Overload operal egal called" << std::endl;
	return (*this);
}

Dog::~Dog(void)
{
	std::cout << "A dog has been destroyed" << std::endl;
}

void	Dog::makeSound(void) const
{
	std::cout << "Ouaaaf.." << std::endl;
}
