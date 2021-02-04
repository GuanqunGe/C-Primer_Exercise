#include "TextQuery.h"
#include "QueryResult.h" //actual use of QueryResult object
#include <sstream>

TextQuery::TextQuery(std::ifstream &in):
file(std::make_shared<std::vector<std::string>>()){

    std::string line;
    while( std::getline(in, line)){

	line_no line_number = file->size();

	std::istringstream ss(line);
	for( std::string word; ss>> word; ){
	    if(word_map.find(word) == word_map.end()){
		//both are right, one directly add a pair, the other first inserts a pair with nullptr, then redirect that pointer to a newly created std::set.
		//word_map.insert({word, std::make_shared<std::set<line_no>>()});
		word_map[word] = std::make_shared<std::set<line_no>>();
	    }
	    word_map[word]->insert(line_number);
	}        

        file->push_back(line);
    } //end while loop
}

QueryResult TextQuery::query(const std::string &s) const{

    static std::shared_ptr<std::set<line_no>> nodata(new std::set<line_no>);

    auto pos = word_map.find(s);
    if( pos == word_map.end())
	return QueryResult(s, nodata, file);
    else
	return QueryResult(s, pos->second, file);
	//return QueryResult(s, word_map[s], file); //word_map is const object, can't use subscript
}
