#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>

bool IsShorter(const std::string &s, decltype(s.size()) sz){
    return s.size() <= sz;
}

// count_if takes unary function
void Counter(const std::vector<std::string> &vec, std::string::size_type sz){

     auto count = std::count_if(vec.begin(), vec.end(), std::bind(IsShorter, std::placeholders::_1, sz));
     std::cout << count << " word(s) have length of " << sz << " or less " << std::endl;
}

int main(int argc, char **argv){

    if(argc < 2){
	std::cerr << "Need extra argument: filename" << std::endl;
  	return -1;
    }

    std::ifstream infile(argv[1]);
    if(!infile){
	std::cerr << "Fail to open file: " << argv[1] << std::endl;
	return -2;
    }

    std::vector<std::string> words;
    for(std::string s; infile >> s; ){ words.push_back(s);}

    Counter(words, 6);
    Counter(words, 8);

    return 0;
}
