#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>

// check if a number is valid phone number
bool valid(const std::string &num){
    for(const auto c : num){
	if(c < '0' || c > '9') return false;
    }
    if(num.size() != 10) return false;
    return true;
}

// turn the phone number into a nicer format
std::string format(const std::string &num){
    return "(" + num.substr(0, 3) + ")" + num.substr(3, 3) + "-" + num.substr(6);
}

struct PersonInfo{
    std::string name;
    std::vector<std::string> phones;
};

int main(int argc, char **argv){
//to read from input file
    if(argc < 2){
	std::cerr << "Need extra argument -- filename " << std::endl;
	return -1;
    }
 
    std::ifstream infile(argv[1]);
    if(!infile){
	std::cerr << "Fail to open the file : " << argv[1] << std::endl;
	return -1;
    }

    //start reading from input file
    std::vector<PersonInfo> people;
    std::string line, word;
    std::istringstream record;
    while(getline(infile, line)){

	record.clear();  // essential!! to turn off the failre bits and make record valid to use again!!
	record.str(line); 

	PersonInfo info;
	record >> info.name;
	while(record >> word){ // at the end of while loop, the eof and fail bit of record is set.

	    info.phones.push_back(word);
        }
	people.push_back(info);
    }

    //print out informations saved in people
    for(const auto &person : people){
	std::cout << person.name << " : ";
 	std::ostringstream formatted, badNums;
	for(const auto &phone : person.phones){
	    if(!valid(phone)){
		badNums << " " << phone;
	    }else{
		formatted << " " << format(phone);
	    }
	} //end of each phone number loop

	if(badNums.str().empty()){
	     //formatted << std::endl;  // endl will add a newline character to formatted but will not print it out on the console
	     std::cout << formatted.str() << std::endl;
	}
	else{
	     std::cout << "Invalid numbers: " << badNums.str() << std::endl;
	}
	    
    }

    infile.close();
    return 0;
}


/************************************************
 * std::ostream << std::endl; endl will add newline to ostream and flush it, ie. print it to the console
 * std::ofstream << std::endl;  endl will add newline to ofstream and flush it, ie. save the newline character to the file, will not print ofstream to the console
 * similarly, std::ostringstream << std::endl; endl will add newline to the osstream, but will not print it to the console
 */
