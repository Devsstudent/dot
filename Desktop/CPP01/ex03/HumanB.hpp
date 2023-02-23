#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"

class	HumanB{
	public:
		HumanB(std::string name);
		~HumanB();
		std::string	get_name(void);
		Weapon	*get_weapon(void);
		void	setWeapon(Weapon &weapon);
		void	attack(void);
	private:
		Weapon		*weapon;
		std::string	name;
};
#endif
