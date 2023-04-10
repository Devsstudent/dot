#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

class	Brain;

class	Animal{
	protected:
		std::string type;
	public:
		Animal(void);
		virtual ~Animal(void);
		Animal(const Animal &a);
		Animal & operator = (const Animal &a);
		void	virtual	makeSound(void) const;
		virtual Brain	*getBrain(void) const = 0;
		void	setType(std::string _type);
		std::string	getType(void) const;
};

#endif
