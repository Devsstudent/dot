#include "global_header.h"
#ifndef CONTACT_HPP
# define CONTACT_HPP

class	Contact {

	public:
		Contact() {};
		~Contact(){};
		void		set_first_name(std::string name);
		void		set_last_name(std::string name);
		void		set_nickname(std::string name);
		void		set_phone_number(std::string number);
		void		set_darkest_secret(std::string secret);
		std::string	get_first_name(void);
		std::string	get_last_name(void);
		std::string	get_nickname(void);
		std::string	get_phone_number(void);
		std::string	get_darkest_secret(void);

	private :
		std::string	first_name;
		std::string	last_name;
		std::string	nickname;
		std::string	phone_number;
		std::string	darkest_secret;
};

#endif
