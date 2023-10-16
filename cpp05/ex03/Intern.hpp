#pragma once

#include "PresidentialPardonForm.hpp"

class Intern{
	public:
		Intern();
		~Intern();
		Intern(Intern const& intern);

		Intern& operator=(Intern const& other);
		int		operator[](std::string);
		
		AForm* makeForm(std::string nameForm, std::string target);
};
