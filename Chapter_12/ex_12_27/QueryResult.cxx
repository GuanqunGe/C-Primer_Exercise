#include "QueryResult.h"
#include "TextQuery.h"

QueryResult::QueryResult( const std::string &s, const TextQuery &tq): word(s), content(tq.GetContent()){
    auto &map = tq.GetMap();
    auto pos = map.find(s);
    if(pos != map.end()){
    	count = pos->second.size();
        line_number.insert( pos->second.begin(), pos->second.end());
  	//std::back_inserter it = std::back_inserter(line_number); //type of it is not std::back_inserter
  	//auto it = std::back_inserter(line_number); //wrong, std::set does not have push_back()
	//std::copy(pos->second.begin(), pos->second.end(), it);
    }else{
	count = 0;
    }
    
}

std::ostream &print(std::ostream &os, const QueryResult &q){

    os << q.GetWord() << " occurs " << q.GetCount() << ( q.GetCount() > 1? " times " : " time") << "\n";

    auto ptr = q.GetContentPtr();
    for( auto &c : q.GetLine()){
	os << "  (line " << c+1 << ") " << (*ptr)[c] << "\n";
    }

    return os;
} 
