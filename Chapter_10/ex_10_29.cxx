#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>

int main(int argc, char **argv){
    if(argc <2 ) {
	std::cerr << "Need extra argument: filename" << std::endl;
	return -1;
    }

    std::ifstream infile(argv[1]);
    if(!infile){
	std::cerr << "Fail to open file: " << argv[1] << std::endl;
	return -2;
    }

    //define istream iterator to read string type, which is binded to a file
    std::istream_iterator<std::string> in(infile), in_eof;
    std::vector<std::string> words(in, in_eof);

    //print out element in vector
    std::for_each(words.cbegin(), words.cend(), [](const std::string &s){ std::cout << s << " "; } );
    std::cout << std::endl;

    return 0;
}
