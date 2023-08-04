#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <iomanip>

class Contact{
	public:
		std::string firstName;
		std::string lastName;
		std::string nickName;
		std::string secret;
		std::string phoneNumber;
		std::string	index;
		static bool stringIsDigit(std::string nbr);
		static std::string input(std::string message);
		void		set_all(int index);
		void		get_all();
		static void write(std::string message, std::string s);
};

#endif