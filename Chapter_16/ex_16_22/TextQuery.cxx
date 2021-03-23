#include "TextQuery.h"
#include "QueryResult.h" //actual use of QueryResult object
#include <sstream>
DebugDelete TextQuery::deleter;

TextQuery::TextQuery(std::ifstream &in):
file(new std::vector<std::string>(), deleter){

    std::string line;
    while( std::getline(in, line)){

	line_no line_number = file->size();

	std::istringstream ss(line);
	for( std::string word; ss>> word; ){
	    if(word_map.find(word) == word_map.end()){
		//both are right, the first one directly add a pair, the second one first inserts a pair with nullptr, then redirect that pointer to a newly created std::set.
		//word_map.insert({word, std::make_shared<std::set<line_no>>()});
		//word_map[word] = std::make_shared<std::set<line_no>>();
	 	word_map[word].reset( new std::set<line_no>(), deleter);
	    }
	    word_map[word]->insert(line_number);
	}        

        file->push_back(line);
    } //end while loop
}

QueryResult TextQuery::query(const std::string &s) const{

    static std::shared_ptr<std::set<line_no>> nodata(new std::set<line_no>, deleter);

    auto pos = word_map.find(s);
    if( pos == word_map.end())
	return QueryResult(s, nodata, file);
    else
	return QueryResult(s, pos->second, file);
	//return QueryResult(s, word_map[s], file); //word_map is const object, can't use subscript
}
