#include "Harl.hpp"

Harl::Harl()
{

}

Harl::~Harl()
{

}

void	Harl::debug(void)
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void	Harl::info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void	Harl::error(void)
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void	Harl::complain(std::string level)
{
	void	(Harl::*func[])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error };
	std::string		level_str[] = { "DEBUG", "INFO", "WARNING", "ERROR" };
	int	i = 0;
	while (i < 4)
	{
		if (level_str[i].compare(level) == 0)
			break ;
		i++;
	}
	switch (i)
	{
		case 0:
				(this->*func[0])();
		case 1:
				(this->*func[1])();
		case 2:
				(this->*func[2])();
		case 3:
				(this->*func[3])();
				break ;
		default:
				std::cout << "Not a valid Identifier" << std::endl;
	}
}
