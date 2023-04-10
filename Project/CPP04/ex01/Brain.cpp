#include "Brain.hpp"

Brain::Brain(void)
{
	for (int i = 0; i < 100; i++)
		ideas[i] = "";
	std::cout << "Brain Constructor Call" << std::endl;
}

Brain::Brain(const Brain &a)
{
	if (this != &a)
	{
		for (int i = 0; i < 100; i++)
			ideas[i] = a.ideas[i];
	}
	std::cout << "Brain copy Constructor Call" << std::endl;
}

Brain &Brain::operator = (const Brain &a)
{
	for (int i = 0; i < 100; i++)
		ideas[i] = a.ideas[i];
	return (*this);
}

Brain::~Brain(void)
{
	std::cout << "Brain Destructor Call" << std::endl;
}

void	Brain::setIdeas(const std::string ideas_str)
{
	int	i;

	for (i = 0; (ideas[i] != "" && i < 100); i++);
	if (i != 100)
		ideas[i] = ideas_str;
}

void	Brain::showIdeas(void)
{
	for (int i = 0; (i < 100); i++)
	{
		if (ideas[i] != "")
			std::cout << ideas[i] << std::endl;
	}
}
