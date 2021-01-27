#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <fstream>

// check if string is longer than sz
bool check_size(const std::string &s, std::string::size_type sz){
    return s.size() >= sz;
}

// eliminate duplicates
void elimDups(std::vector<std::string> &words){
    std::sort(words.begin(), words.end());
    auto end_unique = std::unique(words.begin(), words.end());
    words.erase(end_unique, words.end());
}

void biggies(std::vector<std::string> &words, std::string::size_type sz){

    elimDups(words);
   
    std::stable_sort(words.begin(), words.end(), [](const std::string &s1, const std::string &s2){return s1.size() < s2.size(); });

    //find the first word whose size >= sz
    auto start_find = std::find_if(words.cbegin(), words.cend(), std::bind(check_size, std::placeholders::_1, sz));

    auto count = words.cend() - start_find;
    std::cout << count << " word(s) has length of " << sz << " or larger" << std::endl;

    std::for_each(start_find, words.cend(), [](const std::string &s){ std::cout << s << " "; });
    std::cout << std::endl;
}

int main(int argc, char **argv){
    if(argc < 2){
	std::cerr << "Need extra argument: filename " << std::endl;
	return -1;
    }

    std::ifstream infile(argv[1]);
    if(!infile){
	std::cerr << "Fail to open file: " << argv[1] << std::endl;
	return -2;
    }

    std::vector<std::string> words;
    for(std::string s; infile >> s; ) {words.push_back(s); }

    biggies(words, 5);

    biggies(words, 7);

    return 0;
}
