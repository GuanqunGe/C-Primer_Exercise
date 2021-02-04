#include "TextQuery.h"
#include "QueryResult.h"

TextQuery::TextQuery( std::ifstream &infile):
content(std::make_shared<std::vector<std::string>>()){

    std::string line;
    while( std::getline(infile, line)){
        size_type line_number = content->size();

	std::istringstream ss(line);
	for( std::string word; ss >> word; )
	    word_map[word].insert(line_number);
	content->push_back(line);
    }
}

QueryResult TextQuery::query(const std::string &s) const{

    if( word_map.find(s) == word_map.end())
       	return QueryResult(s);
    else
	return QueryResult(s, *this);
}
