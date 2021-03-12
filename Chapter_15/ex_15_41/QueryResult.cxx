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


// this version of print simply count the frequency of word as the number of lines the word has appears in
std::ostream &simple_print(std::ostream &os, const QueryResult &qr){

    //unsigned count = qr.lines->size();
    std::set<QueryResult::line_no>::size_type count = qr.lines->size();

    os << qr.word << " occurs " << count << (count > 1 ? " times" : " time" ) << ".\n";   

    for(const auto &line : *qr.lines){
	os << "(line " << line + 1 << ") " << qr.file->at(line) << "\n";
    }
    return os;
}

// this version count the frequency of words by readling every line in the file and find the exact word, this 
// probably won't work for result from complicated queries.
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
