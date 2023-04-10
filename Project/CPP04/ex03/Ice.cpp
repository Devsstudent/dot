#include "Ice.hpp"

Ice::Ice(void)
{
  _name = "ice";
}

Ice::Ice(const Ice &a)
{
  _name = a._name;
}

Ice  &Ice::operator = (const Ice &a)
{
  _name = a._name;
  return (*this);
}

Ice::~Ice(void)
{
  std::cout << "Cure Destrucor Called" << std::endl;
}

void  Ice::use(ICharacter& target)
{
  std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

AMateria	*Ice::clone(void) const
{
	return (new Ice());
}

std::string	Ice::getName(void)
{
	return (_name);
}
