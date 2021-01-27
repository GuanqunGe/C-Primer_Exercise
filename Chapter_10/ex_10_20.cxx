#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

void biggies(std::vector<std::string> &words, unsigned sz){

    std::sort(words.begin(), words.end()); // sort in alph order
    auto end_unique = std::unique(words.begin(), words.end()); //move up unique words
    words.erase(end_unique, words.end());

    //now words are in alph order, and are all unique
    //sort it into ascending size order, then alpha order
    std::stable_sort(words.begin(), words.end(), [](const std::string &s1, const std::string &s2){return s1.size() < s2.size(); } );

  
    //std::count_if returns difference_type, ie signed integer type
    auto count = std::count_if(words.cbegin(), words.cend(), [sz](const std::string &s){return s.size() > sz;});
    //unsigned count = std::count_if(words.cbegin(), words.cend(), [sz](const std::string &s){return s.size() > sz;});
    std::cout << count << " word(s) of length longer than " << sz << std::endl;

}

int main(int argc, char **argv){
   
    if(argc < 2) {
	std::cerr << "Need an extra argument: filename" << std::endl;
	return -1;
    }

    std::ifstream infile(argv[1]);
    if(!infile){
	std::cerr << "Couldn't open the file: " << argv[1] << std::endl;
	return -2;
    }

    std::vector<std::string> words;
    for(std::string word; infile >> word; words.push_back(word)) {}

    biggies(words, 6);

    biggies(words, 3);

    return 0;

}
