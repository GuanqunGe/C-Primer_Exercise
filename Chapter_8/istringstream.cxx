#include <iostream> //needed for std::cout
#include <sstream>
#include <string>

int main(){

    std::istringstream ss("Hello world! are you excited?");
    std::string first_word, the_rest;
    ss >> first_word;
    getline(ss, the_rest);

    std::cout << "the rest after 1st word:" << the_rest << std::endl;
    std::cout << "stringstream: " << ss.str() << std::endl;
    //note two things:
    //1. after reading first word, when using getline to get the rest of sstream, the rest starts with a space. ie. the space in between first and second words in the stream in saved into the_rest.
    //2. after reading the istringstream, its str() member still returns the whole associated string.
 
    return 0;
}
