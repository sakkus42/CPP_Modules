#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include "main.hpp"

class PhoneBook
{
	private:
		Contact  *contact;

		void	add(int index);
		int		empty_contact_index();
	public:
		int	is_empty;

		PhoneBook(Contact *contact);
		void	main_menu(std::string input);
};

PhoneBook::PhoneBook(Contact *contact) {this->contact = contact; is_empty = 1;}

void	PhoneBook::main_menu(std::string input) 
{
	if (input == "ADD")
		PhoneBook::add(PhoneBook::empty_contact_index());
}

void	PhoneBook::add(int index)
{
	contact[index].is_empty = 0;
	contact[index].index = index + 1;
	contact[index].set_firstName(Contact::get_input("Enter First Name"));
	contact[index].set_lastName(Contact::get_input("Enter Last Name"));
	contact[index].set_nickName(Contact::get_input("Enter Nick Name"));
	contact[index].set_secret(Contact::get_input("Enter a Darkest Secret Pls"));
	std::string input = Contact::get_input("Enter a phone number");
	for (size_t i = 0; i < input.length(); i++)
	{
		if (!isdigit(input[i]))
		{
			i = 0;
			input = Contact::get_input("please enter number only");
			continue;
		}
	}
	contact[index].set_phoneNbr(input);
}

int		PhoneBook::empty_contact_index()
{
	for (size_t i = 0; i < 8; i++)
	{
		if (contact[i].is_empty)
			return (i);
	}
	return (0);
}



#endif