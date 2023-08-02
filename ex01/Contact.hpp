#ifndef CONTACT_HPP
#define CONTACT_HPP

#include "main.hpp"

class Contact
{
	private:
		std::string first_name;
		std::string last_name;
		std::string nick_name;
		std::string	secret;
		std::string	phone_nbr;
	public:
		Contact();
		std::string		get_phoneNbr();
		std::string		get_firstName();
		std::string		get_lastName();
		std::string		get_nickName();
		std::string		get_secret();
		static std::string		get_input(std::string message);
		void			set_firstName(std::string str);
		void			set_lastName(std::string str);
		void			set_nickName(std::string str);
		void			set_secret(std::string str);
		void			set_phoneNbr(std::string str);
		static void		contact_fill(int index);
		int				is_empty;
		int				index;

};

Contact::Contact() {is_empty = 1;}

std::string Contact::get_firstName()					{return first_name;}
std::string Contact::get_lastName()						{return last_name;}
std::string Contact::get_nickName()						{return nick_name;}
std::string Contact::get_secret()						{return secret;}
std::string	Contact::get_phoneNbr()						{return phone_nbr;}
void		Contact::set_firstName(std::string str) 	{first_name = str;}
void		Contact::set_lastName(std::string str) 		{last_name = str;}
void		Contact::set_nickName(std::string str) 		{nick_name = str;}
void		Contact::set_secret(std::string str) 		{secret = str;}
void		Contact::set_phoneNbr(std::string str) 		{phone_nbr = str;}

std::string		Contact::get_input(std::string message)
{
	std::cout << message << std::endl;
	std::string	input;
	std::cin >> input;
	return (input);
}


#endif