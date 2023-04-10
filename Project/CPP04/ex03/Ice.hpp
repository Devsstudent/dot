#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"

class	ICharacter;

class Ice: public AMateria {
  protected:
    std::string	_name;
  public:
    Ice(void);
    Ice(const Ice &a);
    Ice  & operator = (const Ice &a);
	void	use(ICharacter& target);
	AMateria	*clone(void) const;
	std::string	getName(void);
    virtual ~Ice(void);
};

#endif
