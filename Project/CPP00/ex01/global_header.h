#ifndef GLOBAL_HEADER_H
# define GLOBAL_HEADER_H
# include <iostream>
# include <ctype.h>
# include <stdlib.h>
# include <limits>
# include <errno.h>
# include <stdio.h>
# include <iomanip>
# include "Contact.hpp"
# include "PhoneBook.hpp"

std::string	get_line(void);
void	display_menu(void);
void	reset_stdin(std::string &str);

#endif
