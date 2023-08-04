#include "Contact.hpp"
#include "PhoneBook.hpp"

int main(){
	Contact contact[8];
	PhoneBook phoneBook(contact);
	std::string input;
	std::cout << std::setw(10);
	std::cout << "süleyman" << "|";
	std::cout << std::setw(10);
	std::cout << "akkuş" << "|";
	std::cout << std::setw(10);
	std::cout << "sakkus" << "|";
	std::cout << std::endl;
	std::cout << std::setw(10);
	std::cout << "süleymanasd" << "|";
	std::cout << std::setw(10);
	std::cout << "akkuşasd" << "|";
	std::cout << std::setw(10);
	std::cout << "sakkussad" << "|";
	std::cout << std::endl;
	do
	{
		input = Contact::input("ADD (to 'ADD' to include the person)\nSEARCH (Type a 'SEARCH' to get brief information about people and find the person you want)\nEXIT (For exit, type exit)\n");
		if (input == "ADD")
			phoneBook.add();
		else if (input == "SEARCH")
			phoneBook.search();
	} while (input != "EXIT");
	return (0);
}