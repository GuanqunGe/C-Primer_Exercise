#include <iostream>
#include <map>
#include <string>

using std::string;
using std::multimap;

//eliminate all elements with given key
void elimKey(multimap<string,string> &imap, const string &author){

    multimap<string, string>::iterator pos; 
    while( (pos = imap.find(author)) != imap.end() ){ // if there is an element with key = author
	std::cout << "Erasing " << pos->second << " of " << author << std::endl;
	imap.erase(pos);
    }
}


//print the map
std::ostream &print(std::ostream &os, const multimap<string, string> &imap){
    for(auto iter = imap.begin(); iter != imap.end(); ++iter)
	os << iter->first << ": " << iter->second << "\n";
    return os;
}

int main(){

    multimap<string, string> book_list = {{"John", "BAD BLOOD"}, {"Lippman", "C++"}, {"John", "xxxx"}};
    print(std::cout, book_list) << std::endl;

    elimKey(book_list, "John");

    print(std::cout, book_list) << std::endl;

    elimKey(book_list, "LISI");

    print(std::cout, book_list) << std::endl;

    return 0;
}
