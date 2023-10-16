#include "PresidentialPardonForm.hpp"

void    run(AForm& form, Bureaucrat* brt, Bureaucrat *e_brt = NULL){
    try{
        if (e_brt == NULL){
            form.execute(*brt);
        }
        else{
            form.beSigned(*brt);
            form.execute(*e_brt);
        }
    }catch(std::exception& e){
        std::cerr << e.what() << std::endl;
    }
    std::cout << "---------" << std::endl;
}

int main(){
    {
        ShrubberyCreationForm scf("House");
        Bureaucrat brt("Süleyman", 145);
        Bureaucrat e_brt("Ahmet", 130);
        run(scf, &brt, &e_brt);
        ShrubberyCreationForm scf1("House");
        run(scf1, &brt);
        ShrubberyCreationForm scf2("House");
        Bureaucrat brt1("Ahmet", 148);
        run(scf2, &brt1);
    }
    std::cout << "---------" << std::endl;
    {
        PresidentialPardonForm ppf("Trump");
        Bureaucrat brt("Süleyman", 25);
        Bureaucrat e_brt("Ahmet", 5);
        run(ppf, &brt, &e_brt);
        PresidentialPardonForm ppf1("Trump");
        
        run(ppf1, &brt);
        PresidentialPardonForm ppf2("Trump");
        Bureaucrat brt1("Ahmet", 26);
        run(ppf2, &brt1);
    }
    std::cout << "---------" << std::endl;
    {
        RobotomyRequestForm rrf("Amazon");
        Bureaucrat brt("Süleyman", 72);
        Bureaucrat e_brt("Ahmet", 45);
        run(rrf, &brt, &e_brt);
        RobotomyRequestForm rrf1("Amazon");
        run(rrf1, &brt);
        RobotomyRequestForm rrf2("Amazon");
        Bureaucrat brt1("Ahmet", 76);
        run(rrf2, &brt1);
    }

}