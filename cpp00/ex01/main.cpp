#include "Contact.hpp"
#include "PhoneBook.hpp"

int main(){
	Contact contact[8];
	PhoneBook phoneBook(contact);
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