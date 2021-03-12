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

    //Query q1 = "I";//error, two implicit conversions
    Query q1("I"); //ok, one implicit conversion, const char* -> string
    Query q2 = ~q1;
    Query q3 = Query("this") & Query("class");
    Query q4 = Query("why") | Query("member");
    Query q5 = Query("how") | Query("this") & Query("member"); //when I do cout << q5, seems like the AndQquery part is evaluted before the Query("how") part
    //Query q5 = Query("this") & Query("member") | Query("how");
    // when I do cout << q5, seems like the Query("how") part is evaluted before the AndQuery part

    std::cout << q1 << std::endl;
    std::cout << q2 << std::endl;
    std::cout << q3 << std::endl;
    std::cout << q4 << std::endl;
    std::cout << q5 << std::endl;

    return 0;
}
