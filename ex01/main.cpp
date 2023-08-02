#include "main.hpp"

int main()
{
	Contact		contact[8];
	PhoneBook	phoneBook(contact);
	while (1)
	{
		std::string input;
		input = Contact::get_input("Enter the action you want to do {ADD, SEARCH, EXIT}");
		phoneBook.main_menu(input);
		for (size_t i = 0; i < 8; i++)
		{
			if (contact[i].is_empty)
				break;
			std::cout << contact[i].get_firstName() << std::endl;
			std::cout << contact[i].get_lastName() << std::endl;
			std::cout << contact[i].get_nickName() << std::endl;
			std::cout << contact[i].get_secret() << std::endl;
			std::cout << contact[i].get_phoneNbr() << std::endl;
			std::cout << contact[i].index << std::endl;
		}
	}
	return(0);
}