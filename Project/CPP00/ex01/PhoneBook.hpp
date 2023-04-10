#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include "global_header.h"


class	PhoneBook {
	public:
		PhoneBook(){}
		~PhoneBook(){}
		PhoneBook & operator = (const PhoneBook &a);
		void	handle_input(std::string input);
	private:
		Contact phone_book[8];
};

#endif
