#include <iostream>
#include <string>
std::istream &read(std::istream &is){
/*    while(!is.eof()){
        if(is.fail()) is.clear();
        std::string s; // define string inside the loop, so when is reads eof, the last word will not be printed out twice
	is >> s;
	std::cout << s << std::endl;
    } 
*/
    std::string s;
    while(is >> s) std::cout << s << std::endl;
    is.clear();
    return is;
}

int main(){
    read(std::cin);
    return 0;
}
