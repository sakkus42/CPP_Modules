#include "PhoneBook.hpp"

PhoneBook::PhoneBook(Contact *contact){
    this->contact = contact;
    index = 0;
}

void    PhoneBook::add(){
    if (index == 8)
        index = 0;
    contact[index].set_all(index);
    index += 1;
}

void    PhoneBook::writeCell(std::string str){
    std::cout << std::setw(10);
    str.length() + 1 >= 10 ? std::cout << str.substr(0, 9) << "." << "|" : std::cout << str << "|";
}

void    PhoneBook::display(){

    for (int i = 0; i < 8 && !(contact[i].firstName.empty()) ; i++)
    {
        if (contact[i].firstName.empty())
            break;
        std::cout << std::setfill('*') << std::setw(44);
        std::cout << "" << std::endl;
        std::cout << std::setfill(' ');
        if (i == 0)
        {
            writeCell("Index");
            writeCell("First Name");
            writeCell("Last Name");
            writeCell("Nickname");
            std::cout << std::endl;
        }
        writeCell(contact[i].index);
        writeCell(contact[i].firstName);
        writeCell(contact[i].lastName);
        writeCell(contact[i].nickName);
        std::cout << std::endl;
    }
    std::cout << std::setfill('*') << std::setw(44);
    std::cout << "" << std::endl;
    std::cout << std::setfill(' ');
}

void    PhoneBook::search(){
    if (!index)
    {
        std::cout << "!!!!!Please 'ADD' a Contact First!!!!!" << std::endl << std::endl;
        return ;
    }
    std::string input;
    int index;
    do
    {
        display();
        input = Contact::input("Enter a Index(1-8):");
        index = std::atoi(input.c_str()) - 1;
    } while (!(Contact::stringIsDigit(input)) || !(index >= 0 && index <= 7) || contact[index].firstName.empty());
    contact[index].get_all();
}