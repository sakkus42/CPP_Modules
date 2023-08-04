#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook{
    private:
        Contact *contact;
        void           display();
        void            writeCell(std::string s);
    public:
        PhoneBook(Contact *contact);
        void    add();
        void    search();
        int index;
};

#endif