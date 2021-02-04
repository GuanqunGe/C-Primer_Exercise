#include "QueryResult.h"
#include <sstream>

std::set<QueryResult::line_no>::const_iterator QueryResult::begin() const {
    return lines->cbegin();
}

std::set<QueryResult::line_no>::const_iterator QueryResult::end() const {
    return lines->cend();
}

std::shared_ptr<std::vector<std::string>> QueryResult::get_file() const {
    return file;
}

std::ostream &print( std::ostream &os, const QueryResult &qr){

    unsigned count = 0;
 
    //count the frequency of word
    //since set does not allow duplicate, need to read everyline the word has appeared and count the frequency
    for( const auto &l : *qr.lines){
	std::istringstream ss( (*qr.file)[l] );
	for( std::string w; ss >> w; )
	    if( w == qr.word) ++count;
    }

    //print things out
    os << qr.word << " occurs " << count << (count > 1 ? " times" : " time") << "\n";
    for(const auto &l: *qr.lines){
	os << "(line " << l+1 << ") " << (*qr.file)[l] << "\n";
    }


   return os;
}
