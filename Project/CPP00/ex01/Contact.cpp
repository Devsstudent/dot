#include "Contact.hpp"

void	Contact::set_first_name(std::string name)
{
	this->first_name = name;
}

void	Contact::set_last_name(std::string name)
{
	this->last_name = name;
}

void	Contact::set_nickname(std::string name)
{
	this->nickname = name;
}

void	Contact::set_phone_number(std::string number)
{
	this->phone_number = number;
}

void	Contact::set_darkest_secret(std::string secret)
{
	this->darkest_secret = secret;
}

std::string	Contact::get_first_name(void)
{
	return (this->first_name);
}

std::string	Contact::get_last_name(void)
{
	return (this->last_name);
}

std::string	Contact::get_nickname(void)
{
	return (this->nickname);
}

std::string	Contact::get_phone_number(void)
{
	return (this->phone_number);
}

std::string	Contact::get_darkest_secret(void)
{
	return (this->darkest_secret);
}
