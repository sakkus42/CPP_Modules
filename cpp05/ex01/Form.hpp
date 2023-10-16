#pragma once

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form{
    private:
        const std::string name;
        bool  sign;
        const int grdReqSign;
        const int grdReqExec;
    public:
        Form(std::string name, int grdReqSign, int grdReqExec);
        Form(Form const& form);
        ~Form();
        Form& operator=(Form const& other);

        class GradeTooHighException : public std::exception { public: const char* what() const throw(); };
        class GradeTooLowException  : public std::exception { public: const char* what() const throw(); };

        std::string getName()       const;
        bool        getSign()       const;
        int         getReqSign()    const;
        int         getReqExec()    const;

        void        beSigned(Bureaucrat const& brt) throw(std::exception);
        
};

std::ostream& operator<<(std::ostream& os, Form const& form);