#include "Form.hpp"

Form::Form(std::string _name, int _grdReqSign, int _grdReqExec)
: name(_name), grdReqSign(_grdReqSign), grdReqExec(_grdReqExec)
{}

Form::Form(Form const& form)
: name(form.name), sign(form.sign), grdReqSign(form.grdReqSign), grdReqExec(form.grdReqExec)
{}

Form::~Form() {}

Form& Form::operator=(Form const& other){
    if (&other != this){
        this->sign = other.sign;
    }
    return *this;
}

const char* Form::GradeTooHighException::what() const throw() { return "Grade Too High!"; }
const char* Form::GradeTooLowException::what()  const throw() { return "Grade Too Low!"; }

std::string Form::getName()const   { return this->name; }
bool        Form::getSign()const   { return this->sign; }
int         Form::getReqSign()const{ return this->grdReqSign; }
int         Form::getReqExec()const{ return this->grdReqExec; }

void        Form::beSigned(Bureaucrat const& brt) throw(std::exception) {
    if (brt.getGrade() > this->grdReqSign){
        throw Form::GradeTooLowException();
    }
    this->sign = true;
}

std::ostream& operator<<(std::ostream& os, Form const& form){
    os << form.getName() << ", grade request sign " 
        << form.getReqSign() << ", grade request execute "
        << form.getReqExec();
    return os;
}