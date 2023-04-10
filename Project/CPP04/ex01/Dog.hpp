#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class	Dog: public Animal{
	public:
		Dog(void);
		Dog(const Dog &a);
		Dog & operator = (const Dog &a);
		Brain	*getBrain(void) const;
		virtual ~Dog(void);
	private:
		void	makeSound(void) const;
		Brain	*cerveaux;
};

#endif
