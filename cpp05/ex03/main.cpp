#include "Intern.hpp"


int main(){
    std::cout << "---------" << std::endl;
	{
		Intern  someRandomIntern;
		AForm*   rrf;
       	Bureaucrat brt("Süleyman", 25);
		rrf = someRandomIntern.makeForm("robotomy request", "Bender"); 
		brt.executeForm(*rrf);
	}
    std::cout << "---------" << std::endl;
	system("leaks bureaucrat");
}