#include "FileReplace.hpp"

FileReplace::FileReplace(std::string _fileName, std::string _str1, std::string _str2) : 
fileName(_fileName), str1(_str1), str2(_str2){
    inp = NULL;
    out = NULL;
}

FileReplace::~FileReplace(){
    inp ? delete inp : (void)0;
    out ? delete out : (void)0;
}

bool    FileReplace::openFile(){
    std::ifstream *file = new std::ifstream(fileName);
    this->inp = file;
    if (file->fail()) { 
        return (false);
    }
    return (true);
}

bool    FileReplace::openNewFile(){

    std::ofstream *newFile = new std::ofstream(getNewName());
    this->out = newFile;
    if (newFile->fail()){
        return (false);
    }
    return (true);
}

void    FileReplace::replace(std::string& line){
    int i = line.find(str1);
    while (i != -1)
    {
        line.replace(i, str2.length(), str2);
        i = line.find(str1, i + 1);
    }
}

bool    FileReplace::copyFile(){
    std::string line;
    bool is = false;
    while (std::getline((*this->inp), line)){
        if (line.find(str1) != std::string::npos){
            replace(line);
            is = true;
        }
        (*this->out) << line << std::endl;
    }
    return (is);
}

std::string FileReplace::getNewName() const{
    return (fileName + ".replace");
}
