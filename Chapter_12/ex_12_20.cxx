#include "include/StrBlob.h"
#include "include/StrBlobPtr.h"
#include <iostream>
#include <fstream>

int main(int argc, char **argv){

    if( argc < 2){
	std::cerr << "Need an extra argument: filename" << std::endl;
	return -1;
    }

    std::ifstream infile(argv[1]);
    if( !infile ){
	std::cerr << "Fail to open file: " << argv[1] << std::endl;
	return -2;
    }

    StrBlob content;
    StrBlobPtr cpointer(content); // auto cpointer = content.begin();
				  //wonder if I can use: auto cp = content.begin(); cp != content.end(); cp.incr())
				  //No, because != is not defined for StrBlobPtr class.

    //read from file into StrBlob object
    for( std::string line; std::getline(infile, line); )
	content.push_back(line);

    //print it out
    for( decltype(content.size()) i = 0; i!= content.size(); ++i){
	std::cout<< cpointer.deref() << std::endl;
	cpointer.incr();
    }
  
    infile.close();
    return 0;
}
