#include "Bureaucrat.hpp"

void    bureaucratCrt(std::string name, int grade){
    try{
        Bureaucrat brt(name, grade);
        std::cout << brt << std::endl;
        brt.decrementGrade();
        brt.decrementGrade();
        std::cout << brt << std::endl;
        brt.incrementGrade();
        std::cout << brt << std::endl;
    }catch(Bureaucrat::GradeTooHighException const& e){
        std::cerr << e.what() << std::endl;
    }catch(Bureaucrat::GradeTooLowException const& e){
        std::cerr << e.what() << std::endl;
    }
    std::cout << "---------" << std::endl;
    std::cout << "the function of creation is over, rightly and wrongly"<< std::endl;
}

int main(){
    bureaucratCrt("süleyman", 151); 
    bureaucratCrt("ahmet", 0); 
    bureaucratCrt("Mark", 120); 
    bureaucratCrt("Recep", 89);
    bureaucratCrt("servet", 1);
}