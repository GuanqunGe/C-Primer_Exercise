#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>


void print_vector(const std::vector<std::string> &vec){
     for(auto &e : vec)
	std::cout << e << " ";
     std::cout << std::endl;
}

void elimDups(std::vector<std::string> &vec){

     //start off with a unordered vector of strings
     print_vector(vec);

     //sort it, so duplicate words will be adjacent
     std::sort(vec.begin(), vec.end());
     std::cout << "\nAfter sorting\n" << std::endl; 
     print_vector(vec);

     // 'eliminate' duplicate adjacent words, get iterator after unique words
     std::vector<std::string>::iterator end_unique = std::unique(vec.begin(), vec.end());
     std::cout << "\nAfter calling unique\n" << std::endl; 
     print_vector(vec);

     // get rid of everyting after unique words
     vec.erase(end_unique, vec.end());
     std::cout << "\nAfter erasing\n" << std::endl; 
     print_vector(vec);

}

bool isShorter( const std::string &s1, const std::string &s2){
    return s1.size() < s2.size();
}

int main(int argc, char **argv){
   
    if(argc < 2){
	std::cerr << "Need extra argument - filename " << std::endl;
	return -1;
    }

    std::ifstream infile(argv[1]);
    if(!infile){
	std::cerr << "Fail to open file: " << argv[1] << std::endl;
        return -2;
    }

    std::vector<std::string> vec;
    for(std::string word; infile >> word; )  vec.push_back(word);

    elimDups(vec);
    //std::sort(vec.begin(), vec.end(), isShorter);  // sort does not preserve original order for equal elements 
    std::stable_sort(vec.begin(), vec.end(), isShorter);

    std::cout << "\nAfter sorting by length, while keeping words in alphabetic order\n" << std::endl;
    print_vector(vec);
    return 0;
}
