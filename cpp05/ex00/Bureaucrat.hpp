#include <iostream>
#include <exception>

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
        
        class GradeTooHighException : std::exception { public: const char * what () const throw (); };
        class GradeTooLowException  : std::exception { public: const char * what () const throw (); };
};

std::ostream& operator<<(std::ostream& os, Bureaucrat const& src);