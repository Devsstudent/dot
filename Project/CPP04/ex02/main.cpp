#include "Brain.hpp"
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int  main(void)
{
//  Animal  test;
  const  Animal* i = new Dog();
  const  Animal* j = new Cat();

  j->makeSound();
  i->makeSound();

  delete  j;
  delete  i;
}