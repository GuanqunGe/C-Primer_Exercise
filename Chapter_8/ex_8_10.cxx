#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
std::vector<std::string> ReadFile(const std::string &filename){
    std::vector<std::string> line_vec;

    std::ifstream infile(filename);
    if(!infile){
	std::cerr << "Couldn't open file : " << filename << std::endl;
	return line_vec;
    }

    std::string line;
    while(getline(infile,line))
	line_vec.push_back(line);

    infile.close();
    return line_vec;    
}

std::vector<std::string> ReadStringVec(const std::vector<std::string> &vec){
    std::vector<std::string> wordvec;
    for(auto &line : vec){  //line is a reference to a const string
	std::istringstream strm(line);
        for(std::string word; strm >> word; )
	    wordvec.push_back(word);
    }

    return wordvec;
}

int main(int argc, char **argv){
    if(argc < 2){
	std::cerr << "Need an extra argument -- filename " << std::endl;
        return -1;
    }

    std::vector<std::string> line_vec = ReadFile(argv[1]);
    std::vector<std::string> word_vec = ReadStringVec(line_vec);
    
    for(decltype(word_vec.size()) i = 0; i != word_vec.size(); ++i){
	std::cout << word_vec[i] << " ";
        if((i+1) % 10 == 0) std::cout << std::endl;
    }
    std::cout << std::endl;  //newline for last several words

    return 0;
}
