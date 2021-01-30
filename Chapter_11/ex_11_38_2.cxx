//again, simply replace the occurance of std::map by std::unordered_map, in ex_11_33.cxx
//since map and unordered_map provide same operations for subscripting, find() and insert()
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <unordered_map>
using std::unordered_map;
using std::string;

unordered_map<string, string> build_map(std::ifstream &in){

    string original_word, replacement;
    unordered_map<string, string> trans_map;
  
    //note that getline will always return true as long as the content of the file can be interpreted as string
    //and that it has not reached the end-of-file
    //for example, for a line "asap", original_word will be asap, getline will return true, but replacement will be empty. 
    while(in >> original_word && std::getline(in, replacement)){
 	if( replacement.size() > 1){
	    trans_map[original_word] = replacement.substr(1);
	}else{

	    //if there is no replacement, simply print out error message, and move on
	    std::cerr << "Word: " << original_word << " is missing replacement here" << std::endl;
	}
    }

    return trans_map;
}

//note the return type - "const string &", has to be const because the two input arguments are const.
const string &transform(const string &s, const unordered_map<string, string> &imap){

    if(imap.find(s) != imap.end()){
	return imap.find(s)->second;
    }else{
	return s;
    }
}

std::ostream &word_transformation(std::ostream &os, std::ifstream &map_file, std::ifstream &input){
    
    unordered_map<string, string> trans_map = build_map(map_file);

    string line;
    while(std::getline(input, line)){
	std::istringstream ss(line);
	bool first_word = true;
	string word;
	while( ss >> word){
	    if(first_word) first_word = false;
	    else os << " ";

	    os << transform(word, trans_map);
        }
	os << "\n";

    }

    return os;
}

int main(int argc, char **argv){
 
    if(argc < 3){
	std::cerr << "Need two extra argument: map file, and input file" << std::endl;
	return -1;
    }

    std::ifstream map_file(argv[1]), input_file(argv[2]);
    if( !map_file || !input_file){
	std::cerr << "Fail to open (one of) these files: " << argv[1] << " | " << argv[2] << std::endl;
	return -2;
    }

    word_transformation(std::cout, map_file, input_file) << std::endl;

    return 0;
}
