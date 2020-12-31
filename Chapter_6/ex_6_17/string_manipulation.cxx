#include "string_manipulation.h"
#include <cctype>

bool has_capital(const std::string &s){

     bool has_capital = false;
     for(auto & c: s){  //loop over characters in s.
	if(isupper(c)){
	    has_capital = true;
	    break;
	}
     }

     return has_capital;
}

void to_lowercase(std::string &s){

     for(auto &c : s){
	 c = tolower(c);
     }

}
