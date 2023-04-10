#include "Brain.hpp"
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int  main(void)
{
  const		Animal* i = new Dog();
  const		Animal* j = new Cat();
  Animal	*arr[4] = {new Dog(), new Dog(), new Cat(), new Cat()};
  Cat		a1;
  Cat		a2(a1);
i->getBrain()->setIdeas("Ehehe");
i->getBrain()->showIdeas();

  j->makeSound();
  i->makeSound();

	delete  j;
	delete  i;
	for (int i = 0; i < 4; i++)
		delete arr[i];
}
