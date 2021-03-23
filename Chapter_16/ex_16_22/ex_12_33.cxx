#include "QueryResult.h"
#include "TextQuery.h"
#include <fstream>
#include <iostream>

void RunQueries(std::ifstream &in){
    // to test when the DebugDelete call operator will be executed, for ex_16_23
    QueryResult qr;
    {
        TextQuery tq(in);
        while(true){
	    std::cout << "Enter a word you want to query: enter 'q' to quit" << std::endl;
	    std::string word;
	    if( !(std::cin >> word) || word == "q") break; 
	    print(std::cout, tq.query(word)) << std::endl;
        }
	qr = tq.query("hello");
	// to test when the DebugDelete call operator will be executed, for ex_16_23
        std::cout << "=====================" << std::endl;
    }
    std::cout << "=====================" << std::endl;

}
int main(int argc, char **argv){
    if(argc < 2 ){
	std::cerr << "Need a file to read from" << std::endl;
	return -1;
    }

    std::ifstream infile(argv[1]);
    if(!infile){
	std::cerr << "Fail to open file: " << argv[1] << std::endl;
	return -2;
    }

   RunQueries(infile);

   return 0;
}

