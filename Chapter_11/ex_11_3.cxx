#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <set>

void Counter(std::istream &is, std::map<std::string, unsigned> &map){

    //words to exclude during counting 
    std::set<std::string> exclude = {"The", "And", "Or", "An", "A",
				     "the", "and", "or", "an", "a"};

    //read word from istream and count it if allowed
    for(std::string s; is >> s; )
	if(exclude.find(s) == exclude.end())
	    ++map[s];

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
