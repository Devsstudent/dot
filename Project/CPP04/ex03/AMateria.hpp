#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include "ICharacter.hpp"

class  ICharacter;

class  AMateria{
  protected:
    std::string  materia_name;
  public:
	AMateria(void);
    AMateria(std::string const & type);
    AMateria(const AMateria &a);
    AMateria & operator = (const AMateria &a);
    virtual	~AMateria(void);
    virtual	AMateria* clone() const = 0;
    virtual	void use(ICharacter& target);
	virtual	std::string	getName(void);
};

#endif
