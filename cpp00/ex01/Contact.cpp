#include "Contact.hpp"

static bool isFullSpace(std::string str){
	for (size_t i = 0; i < str.length(); i++)
	{
		if (str[i] != ' ')
			return (false);
	}
	return (true);
}

std::string  Contact::input(std::string message){
    std::cout << message << std::endl;
    std::string input;
    std::getline(std::cin, input);
    if (!(std::cin.good()))
        exit(1);
    if (input.empty() || isFullSpace(input))
        input = Contact::input(message);
    return (input);
}

void    Contact::set_all(int index){
    firstName = input("Please Enter Your Name:");
    lastName = input("Please Enter Your Last Name:");
    nickName = input("Please Enter Your  Nickname:");
    secret = input("Please Enter Your Darkest Secret:");
    this->index = std::to_string(index + 1);
    std::string number;
    do
    {
        number = this->input("Please Enter Your Phone Number(+90 421 123/0543 12/2132123123):");
    } while (!stringIsDigit(number));
    phoneNumber = number;
}

bool   Contact::stringIsDigit(std::string nbr){
    for (size_t i = 0; i < nbr.length(); i++){
        if (!(std::isdigit(nbr[i])) && nbr[i] != '+' && nbr[i] != ' ')
            return (false);
    }
    return (true);
}

void    Contact::write(std::string message, std::string s){
    std::cout << message << s << std::endl;
}

void    Contact::get_all(){
    write("First Name: ",firstName);
    write("Last Name: ", lastName);
    write("Nickname: ", nickName);
    write("Darkest Secret: ", secret);
    write("Phone Number: ", phoneNumber);
}