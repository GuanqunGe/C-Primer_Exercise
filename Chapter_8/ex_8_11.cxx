#include <string>
#include <iostream>
#include <sstream>
#include <vector>

struct PersonInfo{
    std::string name;
    std::vector<std::string> phones;
};

int main(){
    std::vector<PersonInfo> people;
    std::string line, word;

    std::istringstream record;
    while(getline(std::cin, line)){

	record.str(line);   // Using .str(s) member istringstream multiple times successfully changes the string saved in record everytime. But using record in the following steps to write to info failed if without record.clear().
	record.clear();  //this is essential!! to turn off the failre bits and make record valid to use again!!

	PersonInfo info;
	record >> info.name;
	while(record >> word){ // at the end of while loop, the eof and fail bit of record is set.

	    //std::cout << word << std::endl;
	    info.phones.push_back(word);
        }
	people.push_back(info);
    }

    //print out informations saved in people
    for(const auto &person : people){
	std::cout << person.name << " : ";
	for(const auto &phone : person.phones)
	    std::cout << phone << ", ";
        std::cout << std::endl;
    }
    return 0;
}

/*************************
 * all the changes, record.str(line), record.clear() inside the while loop is definitely needed
 * record.str(line) associate object record with a new string read from the keyboard
 * record.clear() clears status of record from the last iteration, and makes record valid again.
 */
