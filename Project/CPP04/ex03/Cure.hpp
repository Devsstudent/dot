#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"

class AMateria;

class  Cure: public AMateria {
  protected:
	std::string	_name;
  public:
    Cure(void);
    Cure(const Cure &a);
    Cure & operator = (const Cure &a);
	void		use(ICharacter &target);
	AMateria	*clone(void) const;
	std::string	getName(void);
    virtual ~Cure(void);
};

#endif
