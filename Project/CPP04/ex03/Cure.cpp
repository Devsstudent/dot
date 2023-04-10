#include "Cure.hpp"

Cure::Cure(void)
{
  _name = "cure";
}

Cure::Cure(const Cure &a)
{
  _name = a._name;
}

Cure  &Cure::operator = (const Cure &a)
{
  _name = a._name;
  return (*this);
}

Cure::~Cure(void)
{
  std::cout << "Cure Destrucor Called" << std::endl;
}

void  Cure::use(ICharacter& target)
{
  std::cout << "* healds " << target.getName() << "'s wounds *" << std::endl;
}

AMateria	*Cure::clone(void) const
{
	return (new Cure());
}

std::string	Cure::getName(void)
{
	return (_name);
}
