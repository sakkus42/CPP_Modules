#pragma once

#include <iostream>
#include <exception>
#include "Form.hpp"

class Form;

class Bureaucrat{
    private:
        const std::string   name;
        int                 grade;
    public:
        Bureaucrat(std::string const& name, int grade);
        ~Bureaucrat();

        Bureaucrat(Bureaucrat const& other);

        Bureaucrat& operator=(Bureaucrat const& other);

        std::string getName() const;
        int         getGrade() const;

        void        incrementGrade();
        void        decrementGrade();
        
        class GradeTooHighException : public std::exception { public: const char * what () const throw (); };
        class GradeTooLowException  : public std::exception { public: const char * what () const throw (); };

        void        signForm(Form& from);
};

std::ostream& operator<<(std::ostream& os, Bureaucrat const& src);