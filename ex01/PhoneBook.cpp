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
    if (str.length() > 10)
        str = str.substr(0,9) + ".";
    std::cout << "|" << std::setw(10) << str << std::flush;
}

void    PhoneBook::display(){
    std::cout <<  std::setw(10) << std::flush;
    writeCell("Index");
    writeCell("First Name");
    writeCell("Last Name");
    writeCell("Nickname");
    std::cout << "|" << std::endl;
    std::cout << std::endl;
    for (int i = 0; i < 8 && !(contact[i].firstName.empty()) ; i++)
    {
        if (contact[i].firstName.empty())
            break;
        std::cout << std::setw(10) << std::flush;
        writeCell(contact[i].index);
        writeCell(contact[i].firstName);
        writeCell(contact[i].lastName);
        writeCell(contact[i].nickName);
        std::cout << "|" << std::endl;
    }
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