#include <iostream>
#include <fstream>
#include <string>
#include <vector>

void ReadFile(std::string filename, std::vector<std::string> &vec){
    std::ifstream infile(filename);
    if(infile){
	std::string word;
	while(infile >> word)
	    vec.push_back(word);
        infile.close();
    }
    else{
	std::cerr << "Fail to open file: " << filename << std::endl;
    } 
}

int main(){
    std::vector<std::string> word_vec;
    ReadFile("ex_8_3.txt", word_vec);
 
    for(const auto &word : word_vec)
        std::cout << word << " ";
    std::cout << std::endl;

    return 0;
}
