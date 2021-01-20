#include <iostream>
#include <string>

using std::string;

void separate_num_alpha(const string &s, const string &num, const string &alpha){

    decltype(s.size()) pos = 0;
    while( (pos = s.find_first_of(num, pos)) != string::npos){
	std::cout << "Find a number: " << s[pos] << " at pos: " << pos <<  std::endl;
	++pos;
    }

    std::cout << "Now move on to alphabetic letters:" << std::endl;
    pos = 0;  //reset the pos to be the start of string
    while( (pos = s.find_first_of(alpha, pos)) != string::npos){
	std::cout << "Find a letter: " << s[pos] << " at pos: " << pos << std::endl;
	++pos;
    }
   
}

void separate_num_alpha_v2(const string &s, const string &num, const string &alpha){


    decltype(s.size()) pos = 0;
    while( (pos = s.find_first_not_of(alpha, pos)) != string::npos){
	// if we find a char that's not a letter
	
	// if this char is a number, print it out. Otherwise do nothing
	if( num.find( s[pos] ) != string::npos)
	    std::cout << "Find a number: " << s[pos] << " at pos: " << pos << std::endl;

	++pos;  //increment the pos to move on to the next unprocessed element
    }

    std::cout << "Now move on to alphabetic letters: " << std::endl;
    pos = 0;
    while( (pos = s.find_first_not_of(num, pos)) != string::npos){
	if( alpha.find( s[pos] ) != string::npos)
	    std::cout << "Find a letter: " << s[pos] << " at pos: " << pos << std::endl;
	++pos;
    }
    
}

int main(){
    string num = "1234567890", alpha; 

    //generate a long string containing alphabetic letters
    char ch = 'a';
    for(int i = 0 ; i < 26; ++i, ++ch)
	alpha.push_back(ch);
    ch = 'A';
    for(int i = 0 ; i < 26; ++i, ++ch)
	alpha.push_back(ch);
   
    //std::cout << alpha << std::endl;
 
    separate_num_alpha("he%1&llo0heoshe8fh3uhfu", num, alpha);

    std::cout << "\n\nSecond method: " << std::endl;
    separate_num_alpha_v2("he%1&llo0heoshe8fh3uhfu", num, alpha);
    return 0;
}
