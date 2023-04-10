#include "Dog.hpp"

Dog::Dog(void)
{
	setType("Dog");
	cerveaux = new Brain();
	std::cout << "A dog has been constructed" << std::endl;
}

Dog::Dog(const Dog &a)
{
	if (this != &a)
	{
		setType(a.getType());
		cerveaux = new Brain(*a.cerveaux);
	}
	std::cout << "A dog has been constructed by copy" << std::endl;
}

Dog	&Dog::operator = (const Dog &a)
{
	setType(a.getType());
	delete cerveaux;
	cerveaux = new Brain(*a.cerveaux);
	std::cout << "Overload operal egal called" << std::endl;
	return (*this);
}

Dog::~Dog(void)
{
	std::cout << "A dog has been destroyed" << std::endl;
	if (cerveaux)
		delete cerveaux;
	else
		std::cout << "not brain" << std::endl;
}

Brain	*Dog::getBrain(void) const
{
	return (cerveaux);
}

void	Dog::makeSound(void) const
{
	std::cout << "Ouaaaf.." << std::endl;
}
