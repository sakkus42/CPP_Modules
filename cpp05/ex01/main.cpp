#include "Bureaucrat.hpp"

void    bureaucratCrt(std::string name, int grade, Form form){
    try{
        Bureaucrat brt(name, grade);
        brt.signForm(form);
    }catch(std::exception& e){
        std::cerr << e.what() << std::endl;
    }
    std::cout << "the function of creation is over, rightly and wrongly"<< std::endl;
    std::cout << "---------" << std::endl;
}

int main(){
    bureaucratCrt("süleyman", 100, Form("Operation Water", 99, 0));

}