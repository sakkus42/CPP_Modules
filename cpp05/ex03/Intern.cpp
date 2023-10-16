#include "Intern.hpp"

Intern::Intern() {}

Intern::~Intern() {}

Intern::Intern(Intern const& intern) { *this = intern; }

Intern& Intern::operator=(Intern const& other) { (void)other; return *this; }

AForm* Intern::makeForm(std::string nameForm, std::string target){
	AForm *res;
	switch ((*this)[nameForm])
	{
	case 0:
		res = new ShrubberyCreationForm(target);
		break;
	case 1:
		res =  new RobotomyRequestForm(target);
		break;
	case 2:
		res = new PresidentialPardonForm(target);
		break;
	default:
		std::cout << "Give me a real form name, man." << std::endl;
		return nullptr;
	}
	std::cout << "Intern creates " << *res << std::endl;
	return res;
}

int Intern::operator[](std::string value){
	std::string forms[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	int i = 0;
	while (i < 3 && forms[i].compare(value))
		i++;
	return i;
}
