#include "Ice.hpp"
#include "Cure.hpp"
#include "AMateria.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

int main()
{
	IMateriaSource* src = new MateriaSource();
	AMateria *test = new Ice();
	src->learnMateria(test);
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	AMateria* tmp_bis;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp_bis = tmp;
	me->unequip(0);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	delete bob;
	delete tmp_bis;
	delete me;
	delete src;
	return 0;
}

/*
int	main(void)
{
	Ice		ice;
	Cure	cure;
	AMateria	*i = new Ice();
	AMateria	*j = NULL;
	ICharacter	*john = new Character("John");
	ICharacter	*eric = new Character("Eric");

	john->equip(i);
	eric->equip(j);
	john->use(5, *eric);
	eric->use(0, *john);
	j = i->clone();
	eric->equip(j);
	eric->use(0, *john);

	eric->unequip(0);
	delete i;
	delete j;
	delete john;
	delete eric;
}*/
