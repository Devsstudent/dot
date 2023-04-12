#include "global_header.h"

void	reset_stdin(std::string &str)
{
	str = "";
	std::cin.clear();
	clearerr(stdin);
	std::cout << std::endl;
}

static void ask_input(std::string output, std::string &str)
{
	bool	input;

	std::cout << output;
	input = getline(std::cin, str);
	while (!input || str.size() == 0)
	{
		input = getline(std::cin, str);
		if (!input)
			reset_stdin(str);
		if (str.size() == 0)
			std::cout << output;
	}
}

static bool	check_number(std::string &str)
{
	for (std::string::iterator it=str.begin(); it!=str.end(); ++it)
	{
		if (!isdigit(*it))
			return (false);
	}
	return (true);
}

static void	ask_number(std::string output, std::string &str)
{
	bool	input;

	std::cout << output;
	input = getline(std::cin, str);
	if (!input)
		reset_stdin(str);
	while (!input || str.size() == 0 || !check_number(str))
	{
		std::cout << output;
		input = getline(std::cin, str);
		if (!input)
			reset_stdin(str);
	}
}

//Function to loop to the last contact checking if it's more than the eighth

static int	get_index_phonebook(Contact phone_book[8])
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (!phone_book[i].get_first_name().size())
			return (i);
		i++;
	}
	return (i);
}

static void add(Contact phone_book[8])
{
	int			i;
	static int	j;
	std::string		str;
	std::string		&ref_str = str;

	i = get_index_phonebook(phone_book);
	if (j != 0 || i == 8)
	{
		j += 1;
		i = (j % 8) - 1;
	}
	ask_input("First Name: ", ref_str);
	phone_book[i].set_first_name(str);
	ask_input("Last Name: ", ref_str);
	phone_book[i].set_last_name(str);
	ask_input("NickName: ", ref_str);
	phone_book[i].set_nickname(str);
	ask_number("PhoneNumber: ", ref_str);
	phone_book[i].set_phone_number(str);
	ask_input("Darkest Secret: ", ref_str);
	phone_book[i].set_darkest_secret(str);
}

static void	output_name(std::string str)
{
	size_t	size;

	size = str.size();
	if (size >= 10)
	{
		str = str.substr(0, 10);
		str[9] = '.';
	}
	std::cout << std::setw(10) << str << "|";
}

static void	display_info(Contact &contact)
{
	std::cout << "First Name : " << contact.get_first_name() << std::endl;
	std::cout << "Last Name : " << contact.get_last_name() << std::endl;
	std::cout << "Nickname : " << contact.get_nickname() << std::endl;
	std::cout << "Number : " << contact.get_phone_number() << std::endl;
	std::cout << "Darkest secrets : " << contact.get_darkest_secret() << std::endl;
	std::cout << std::endl;
}

static void	search(Contact phone_book[8])
{
	int			j;
	int			i;
	std::string	str;
	bool		input;

	i = 1;
	str = "";
	j = get_index_phonebook(phone_book);
	std::cout << "|";
	std::cout << std::setw(10) << "index" << "|";
	std::cout << std::setw(10) << "first name"  << "|";
	std::cout << std::setw(10) << "last name" << "|";
	std::cout << std::setw(10) << "Nickname" << "|" << std::endl;
	while (i <= j)
	{
		std::cout << "|";
		std::cout << std::setw(10) << i;
		std::cout << "|";
		output_name(phone_book[i - 1].get_first_name());
		output_name(phone_book[i - 1].get_last_name());
		output_name(phone_book[i - 1].get_nickname());
		std::cout << std::endl; 
		i++;
	}
	if (j == 0)
		return ;
	std::cout << "Wich one do you want to select ? ";
	input = getline(std::cin, str);
	if (!input)
		reset_stdin(str);
	while (!input || j == 0 || atoi(str.c_str()) <= 0
			|| atoi(str.c_str()) > i || atoi(str.c_str()) > j)
	{
		std::cout << "Wich one do you want to select ? ";
		input = getline(std::cin, str);
		if (!input)
			reset_stdin(str);
	}
	std::cout << std::endl;
	if (atoi(str.c_str()) > 0)
		display_info(phone_book[atoi(str.c_str()) - 1]);
}

void	PhoneBook::handle_input(std::string input)
{
	if (input == "ADD")
		add(this->phone_book);
	else if (input == "SEARCH")
		search(this->phone_book);
	display_menu();
}
