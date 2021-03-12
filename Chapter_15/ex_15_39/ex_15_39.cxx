#include <iostream>
#include <fstream>
#include <string>
#include "TextQuery.h"
#include "QueryResult.h"
#include "Query.h"

int main(int argc, char **argv){
    if(argc < 2){
	std::cerr << "Need extra argument: filename to read" << std::endl;
	return -1;
    }

    std::ifstream infile(argv[1]);
    if(!infile){
	std::cerr << "Fail to open file: " << argv[1] << std::endl;
	return -2;
    }

    TextQuery tq(infile);

    Query q = Query("so") | Query("constructor") & Query("call");
    std::cout << q << std::endl;
    simple_print(std::cout, q.eval(tq)) << std::endl;
    return 0;
}
