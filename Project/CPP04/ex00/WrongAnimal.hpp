#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iostream>

class	WrongAnimal{
	private :
		std::string	type;
	public :
		WrongAnimal(void);
		WrongAnimal(const WrongAnimal &a);
		WrongAnimal & operator = (const WrongAnimal &a);
		virtual ~WrongAnimal(void);
		void	makeSound(void)	const;
		void	setType(std::string _type);
		std::string	getType(void) const;
};

#endif
