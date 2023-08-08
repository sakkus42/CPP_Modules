#include "FileReplace.hpp"

int main(int ac, char *arv[]){
    if (ac != 4){
        std::cout << "Invalid Argument Count" << std::endl;
        return (1);
    }
    FileReplace f(arv[1], arv[2], arv[3]);
    if (!f.openFile()){
        std::cout << arv[2] <<": No Such File" << std::endl;

    }else if (!f.openNewFile()){
        std::cout << "Could not Create New File" << std::endl;

    }else if (!f.copyFile()){
        std::cout << f.getNewName() << ": Relocation Failed but Copy of File was Created" << std::endl;
    }else{
        std::cout << f.getNewName() << ": Relocation Succeeded"<< std::endl;
    }
    return (0);
}