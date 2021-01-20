// question: capital letters, are they ascender? or should be counted as either ascender or descender?

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using std::string;

// does the word have neither cond1 nor cond2?
bool is_correct_word(const string &word, const string &cond1, const string &cond2){
    if( (word.find_first_of(cond1)) == string::npos && (word.find_first_of(cond2)) == string::npos) 
	return true;
    return false;
}

int main(int argc, char **argv){
    if(argc < 2){
	std::cout << "Need extra argument: filename " << std::endl;
	return -1;
    }

    std::ifstream infile(argv[1]);
    if(!infile){
	std::cerr << "Fail to open file: " << argv[1] << std::endl;
	return -2;
    }

    string ascender("bdfhijklt"), descender("gjpqy");

    // loop over the file, find the 'word'
    string line, word, result;
    while(getline( infile, line)){
	std::istringstream iss(line);
	while(iss >> word){   // or, directly, infile >> word. 
	    if( is_correct_word(word, ascender, descender) ){
		if(word.size() > result.size()){
		    result = word;
		}
	    } //end of if 
	}	
    }

    if(result.empty()){
	std::cout << "There is no word in file: " << argv[1] << " that contains neither ascenders now descenders" << std::endl;
    }else{
	std::cout << "The longest word that contains neither ascenders nor descenders in file: " << argv[1] << " is: " << result << " with length " << result.size() << std::endl;
    }

    return 0;
}
