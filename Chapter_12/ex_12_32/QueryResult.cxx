#include "QueryResult.h"
#include "../include/ConstStrBlobPtr.h"
#include <sstream>

std::ostream &print( std::ostream &os, const QueryResult &qr){

    unsigned count = 0;
 
    //count the frequency of word
    //since set does not allow duplicate, need to read everyline the word has appeared and count the frequency
    for( const auto &l : *qr.lines){
        ConstStrBlobPtr cptr( qr.file, l);
	std::istringstream ss( cptr.deref() );
	for( std::string w; ss >> w; )
	    if( w == qr.word) ++count;
    }

    //print things out
    os << qr.word << " occurs " << count << (count > 1 ? " times" : " time") << "\n";
    for(const auto &l: *qr.lines){
	ConstStrBlobPtr cptr( qr.file, l);
	os << "(line " << l+1 << ") " << cptr.deref() << "\n";
    }


   return os;
}
