#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"

class	MateriaSource: public IMateriaSource {
	private:
		AMateria *learnedMaterial[4];
	public:
		MateriaSource(void);
		MateriaSource(const MateriaSource &a);
		MateriaSource &operator = (const MateriaSource &a);
		virtual ~MateriaSource(void);
		void		learnMateria(AMateria *mat);
		AMateria	*createMateria(std::string	const & type);
};

#endif
