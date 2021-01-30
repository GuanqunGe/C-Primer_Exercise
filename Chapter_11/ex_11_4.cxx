#include <iostream>
#include <fstream>
#include <string>
#include <cctype> //to remove punctuation, upper case letter
#include <algorithm> 
#include <map>
#include <set>

void Trim_String(std::string &s){

    //method 1: tranverse through s
    for(auto iter = s.begin(); iter != s.end(); ){
	*iter = tolower(*iter);
	if( ispunct(*iter)){ //if character is' punctuation, remove it
	    iter = s.erase(iter);  //after erasion, iter points to the element after removed element
	}else ++iter;
    }

    //method 2: use remove_if and for_each
    auto iter = std::remove_if(s.begin(), s.end(), [](const char s){return ispunct(s); });
    s.erase(iter, s.end());
    std::for_each(s.begin(), s.end(), [](char &c){ c = tolower(c); });
}

void Counter(std::istream &is, std::map<std::string, unsigned> &map){

    //words to exclude during counting 
    std::set<std::string> exclude = {"the", "and", "or", "an", "a"};

    //read word from istream and count it if allowed
    for(std::string s; is >> s; ){
	Trim_String(s);
	if(exclude.find(s) == exclude.end())
	    ++map[s];
    }
}

//print the map to an ostream
std::ostream &Printer(std::ostream &os, const std::map<std::string, unsigned> &map){

    for(auto &pair : map){
	os << pair.first << ": " << pair.second << "\n";
    }

    return os;
}

int main(int argc, char **argv){

    if(argc < 2){
	std::cerr << "Need an extra argument: filename " << std::endl;
	return -1;
    }

    std::ifstream infile(argv[1]);
    if(!infile){
	std::cerr << "Fail to open file: " << argv[1] << std::endl;
	return -2;
    }

    std::map<std::string, unsigned> word_count;
    Counter(infile, word_count);
    Printer(std::cout, word_count) << std::endl;

    return 0;
}
