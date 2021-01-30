#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>

using std::multimap;
using std::string;
using std::vector;

//pretty print the map
//- list author and their works alphabetically
std::ostream &pretty_print(std::ostream &os, const multimap<string, string> &imap){

    vector<string> authors; //stores author name
    vector<vector<string>> book_list; //store author works, one-to-to correspondence to vector 'authors'

    multimap<string, string>::const_iterator pos = imap.begin();
    while( pos != imap.end() ){ // while there is still element to look at
        authors.push_back(pos->first);
	auto pos_end = imap.upper_bound( pos->first ); // find the iterator upper range for current author

	vector<string> books; //store works for current author
	while( pos != pos_end){
	    books.push_back(pos->second);
	    ++pos;
	}
	std::sort(books.begin(), books.end()); //sort his/her works alphabetically
        book_list.push_back(books);
	
    }

    //print it out!
    for( decltype(authors.size()) i = 0; i!= authors.size(); ++i){
	os << "Author: " << authors[i] << ", booklist: ";
	for(const auto &s:book_list[i])
	    os << s << " | ";
	os << "\n";
    }

    return os;

}

// print the map element-by-element
std::ostream &normal_print(std::ostream &os, const multimap<string, string> &imap){
    for(auto iter = imap.begin(); iter != imap.end(); ++iter)
        os << iter->first << ":" << iter->second << "\n";
    return os;
}
int main(){

    multimap<string, string> books = {{"AA", "Bok"}, {"John", "Bod blood"}, {"Lippman", "C++"}, {"John", "Bad blood"} };

    //in multimap, elements are sorted by key
    //for elements with same key, they sit next to each other, but the order of these element
    //is not alphebetical order, instead is the same as the initialization/insertion.
    normal_print(std::cout, books) << std::endl;

    pretty_print(std::cout, books) << std::endl;

    return 0;
}
