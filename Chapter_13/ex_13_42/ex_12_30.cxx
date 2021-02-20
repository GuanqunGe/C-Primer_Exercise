/**
 * folder ex_13_42 is copied from Chapter_12/ex_12_30, for the purpose of testing
 * the implementation of StrVec in place of std::vector<std::string>
 *
 * - file ex_12_30.cxx is not changed from Chapter_12/ex_12_30
 * - class TextQuery and QueryResult have been modified to use StrVec instead of vector<string>
 * - due to implementation of print() function used by QueryResult class, an index operator is added to class StrVec.
 *
 *   To get executable, do: 
 *   	g++ -o ex_12_30 -std=c++11 ex_12_30.cxx TextQuery.cxx QueryResult.cxx ../ex_13_39/StrVec.cxx
 */

#include "QueryResult.h"
#include "TextQuery.h"
#include <fstream>
#include <iostream>

void RunQueries(std::ifstream &in){
    TextQuery tq(in);
    while(true){
	std::cout << "Enter a word you want to query: enter 'q' to quit" << std::endl;
	std::string word;
	if( !(std::cin >> word) || word == "q") break; 
	print(std::cout, tq.query(word)) << std::endl;
    }
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

