#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void)
{
	for (int i = 0; i < 4; i++)
		learnedMaterial[i] = NULL;
	std::cout << "MateriaSource Constructor Called" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource &a)
{
	for (int i = 0; i < 4; i++)
		learnedMaterial[i] = a.learnedMaterial[i];
	std::cout << "MateriaSource Copy Constructor Called" << std::endl;
}

MateriaSource &MateriaSource::operator = (const MateriaSource &a)
{
	for (int i = 0; i < 4; i++)
	{
		if (learnedMaterial[i])
			delete learnedMaterial[i];
	}
	for (int i = 0; i < 4; i++)
		learnedMaterial[i] = a.learnedMaterial[i]->clone();
	return (*this);
}

MateriaSource::~MateriaSource(void)
{
	for (int i = 0; i < 4; i++)
		if (learnedMaterial[i])
			delete learnedMaterial[i];
	std::cout << "MateriaSource Destructor Called" << std::endl;
}

void	MateriaSource::learnMateria(AMateria *mat)
{
	for (int i = 0; i < 4; i++)
	{
		if (!learnedMaterial[i])
		{
			learnedMaterial[i] = mat;
			return ;
		}
	}
}

AMateria	*MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
	{
		if (learnedMaterial[i] && type == learnedMaterial[i]->getName())
			return (learnedMaterial[i]->clone());
	}
	return (0);
}
