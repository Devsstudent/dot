#include "global_header.h"

void	display_menu(void)
{
	std::cout << "Enter ADD to add some contact to your personal PhoneBook" << std::endl;
	std::cout << "Enter SEARCH to view and search in your personal PhoneBook" << std::endl;
	std::cout << "Enter EXIT to exit this beautiful program" << std::endl;
}

int	main(void)
{
	std::string	input;
	bool		return_get_line;
	PhoneBook	phone_book;

	std::cout << "Welcome to my PhoneBook program :)" << std::endl;
	display_menu();
	return_get_line = getline(std::cin, input);
	if (!return_get_line)
	{
		display_menu();
		reset_stdin(input);
	}
	while (input != "EXIT")
	{
		phone_book.handle_input(input);
		return_get_line = getline(std::cin, input);
		if (!return_get_line)
		{
			display_menu();
			reset_stdin(input);
		}
	}
}
