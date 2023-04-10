#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void): type("None")
{
	std::cout << "Wrong Animal Constructor Called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &a)
{
	type = a.type;
	std::cout << "Wrong Animal copy Constructor Called" << std::endl;
}

WrongAnimal &WrongAnimal::operator = (const WrongAnimal &a)
{
	type = a.type;
	return (*this);
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "Wrong Animal Desctructor Called" << std::endl;
}

void	WrongAnimal::makeSound(void) const
{
	std::cout << "Wrong Animal sound .." << std::endl;
}

std::string	WrongAnimal::getType(void) const
{
	return (type);
}

void	WrongAnimal::setType(std::string _type)
{
	type = _type;
}
