#include <fstream>
#include <vector>
#include <string>
#include <iostream>

void ReadFile(std::string filename, std::vector<std::string> &vec){
    std::cout << "Reading files" << std::endl;
    std::ifstream f(filename);
    if(f){
	std::string line;
	while(getline(f, line)) vec.push_back(line);
	f.close();
    }
    else{
        std::cerr << "Couldn't open file: " << filename << std::endl;
    }
}

int main(){
    std::vector<std::string> read;
    ReadFile("ex_8_3.txt", read);
    for(const auto &line : read)
	std::cout << line << std::endl;
    return 0;
}
