// ex_9_47_v0.cxx is not so good, so here is an updated version.
#include <iostream>
#include <string>

using std::string;

// print out characters in s that also sits in str_to_find
void find_char(const string &s, const string &str_to_find){

    decltype(s.size()) pos = 0;
    while( (pos = s.find_first_of(str_to_find, pos)) != string::npos){
	std::cout << "Find a character: " << s[pos] << " at pos: " << pos <<  std::endl;
	++pos;
    }

}

// second method to print out characters in s that also sits in str_to_find
void find_char_v2(const string &s, const string &str_to_find){


    decltype(s.size()) pos = 0, last_pos = pos;
    while( (pos = s.find_first_not_of(str_to_find, pos)) != string::npos){
	// if we find a char that's not inside str_to_find
	// that means characters before it and after the last pos are characters within str_to_find
	for( ; last_pos < pos; ++last_pos)
	    std::cout << "Find a character: " << s[last_pos] << " at pos: " << last_pos << std::endl;

  	++last_pos;
	++pos;  //increment the pos to move on to the next unprocessed element
    }

    //print out the last several characters
    for( ; last_pos < s.size(); ++last_pos)
	std::cout << "Find a character: " << s[last_pos] << " at pos: " << last_pos << std::endl;

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
 
    find_char("he%1&llo0heoshe8fh3uhfu", num);
    find_char("he%1&llo0heoshe8fh3uhfu", alpha);

    std::cout << "\n\nSecond method: " << std::endl;
    find_char_v2("he%1&llo0heoshe8fh3uhfu", num);
    find_char_v2("he%1&llo0heoshe8fh3uhfu", alpha);
    return 0;
}
