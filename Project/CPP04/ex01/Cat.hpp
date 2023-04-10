#ifndef CAT_HPP
# define CAT_HPP
# include "Animal.hpp"
# include "Brain.hpp"

class	Cat: public Animal{
	public :
		Cat(void);
		Cat(const Cat &a);
		Cat & operator = (const Cat &a);
		Brain	*getBrain(void) const;
		virtual ~Cat(void);
	private:
		void	makeSound(void) const;
		Brain	*cerveaux;
};

#endif
