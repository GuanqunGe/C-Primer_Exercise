#include <iostream>
#include <map>
#include <utility>
#include <string>

int main(){
    std::map<std::string, int> imap;


    // type of pair: pair<const string, int>
    std::map<std::string, int>::value_type pair("Thursday", 5);
    //pair.first = "Friday" ;  //wrong


    // type of pair_1: pair<const string, int>
    // note that the constness of string did not go away
    auto pair_1 = std::map<std::string, int>::value_type("Hey", 2);
    std::cout << pair_1.first << " " << pair_1.second << std::endl;
    //pair_1.first = "Bye";
    pair_1.second = 0;
    std::cout << pair_1.first << " " << pair_1.second << std::endl;

 
    // type of pair_2: pair<string, int>
    std::pair<std::string, int> pair_2 = std::map<std::string, int>::value_type("Hello", 1);
    pair_2.first = "Hi";
    std::cout << pair_2.first << " " << pair_2.second << std::endl;


    return 0;

}
