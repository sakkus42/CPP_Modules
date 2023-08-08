#ifndef FileReplace_HPP
#define FileReplace_HPP

#include <iostream>
#include <fstream>

class FileReplace{
    private:
        std::string     fileName;
        std::string     str1;
        std::string     str2;
        std::ifstream*  inp;
        std::ofstream*  out;
        void            replace(std::string& line);
    public:
        FileReplace(std::string fileName, std::string str1, std::string str2);
        ~FileReplace();
        bool        openFile() ;
        bool        openNewFile();
        bool        copyFile();
        std::string getNewName() const;
};

#endif