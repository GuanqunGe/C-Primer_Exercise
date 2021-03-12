#ifndef DERIVED_QUERY_H
#define DERIVED_QUERY_H

#include "Query_base.h"
#include "QueryResult.h"
#include "TextQuery.h"
#include "Query.h"
#include <string>
#include <iterator>
#include <algorithm>

class WordQuery : public Query_base{
    friend class Query;
    WordQuery(const std::string &s): query_word(s) {
    }
    QueryResult eval(const TextQuery &t) const { return t.query(query_word); }
    QueryResult eval(const TextQuery &t, QueryResult::line_no line_limit) const { return t.query(query_word, line_limit); }
    std::string rep() const { 
	return query_word; }
    std::string query_word;
};

class NotQuery : public Query_base{
    friend Query operator~(const Query &);
    NotQuery(const Query &q) : query(q) {
    }
    QueryResult eval(const TextQuery &t) const;
    QueryResult eval(const TextQuery &t, QueryResult::line_no line_limit) const;
    std::string rep() const { 
	return "~(" + query.rep() + ")"; 
    }
    Query query;
};

//Binary class
class BinaryQuery : public Query_base{
protected:  //so that derived class from BinaryQuery can use its constructor
    BinaryQuery(const Query &l, const Query &r, const std::string &s):
	lhs(l), rhs(r), opSym(s) {}
    std::string rep() const {
	return "(" + lhs.rep() + " " + opSym + " " + rhs.rep() + ")";
    }
    Query lhs, rhs;
    std::string opSym; //operator symbol
};

class AndQuery : public BinaryQuery{
    friend Query operator&(const Query&, const Query&);
    AndQuery(const Query &l, const Query &r, const std::string &s):
	BinaryQuery(l, r, s){
    }
    QueryResult eval(const TextQuery &t) const;
    QueryResult eval(const TextQuery &t, QueryResult::line_no line_limit) const;
};

class OrQuery : public BinaryQuery{
    friend Query operator|(const Query&, const Query&);
    OrQuery(const Query &l, const Query &r, const std::string &s):
	BinaryQuery(l, r, s){
    }
    QueryResult eval(const TextQuery &t) const;
    QueryResult eval(const TextQuery &t, QueryResult::line_no line_limit) const;
};

QueryResult NotQuery::eval(const TextQuery &t) const{
    auto result = query.eval(t); //type of result is QueryResult

    std::shared_ptr<std::set<line_no>> lines = std::make_shared<std::set<line_no>>(); //empty set in the heap

    line_no total_num_lines = result.get_file()->size();
    auto line_begin = result.begin(), line_end = result.end(); //iterator into the set<line_no>
    for(line_no i = 0 ; i < total_num_lines; ++i){
	if( line_begin == line_end ||  *line_begin != i){ 
	//if( line_begin == line_end || (line_begin != line_end && *line_begin != i) )
	    lines->insert(i);
 	}
	else{
	    ++line_begin;
  	}
    }

    return QueryResult(rep(), lines, result.get_file());
}

QueryResult NotQuery::eval(const TextQuery &t, QueryResult::line_no line_limit) const{
    auto result = query.eval(t); //type of result is QueryResult

    std::shared_ptr<std::set<line_no>> lines = std::make_shared<std::set<line_no>>(); //empty set in the heap

    line_no total_num_lines = result.get_file()->size();
    auto line_begin = result.begin(), line_end = result.end(); //iterator into the set<line_no>
    for(line_no i = 0 ; i < std::min(total_num_lines, line_limit); ++i){
	if( line_begin == line_end ||  *line_begin != i){ 
	//if( line_begin == line_end || (line_begin != line_end && *line_begin != i) )
	    lines->insert(i);
 	}
	else{
	    ++line_begin;
  	}
    }

    return QueryResult(rep(), lines, result.get_file());
}


QueryResult AndQuery::eval(const TextQuery &t) const{
    auto left_result = lhs.eval(t);
    return eval(t, left_result.get_file()->size());
}

QueryResult AndQuery::eval(const TextQuery &t, QueryResult::line_no line_limit) const{

    auto left_result = lhs.eval(t, line_limit), right_result = rhs.eval(t, line_limit);
    auto left_line_begin = left_result.begin(), left_line_end = left_result.end(),
	 right_line_begin = right_result.begin(), right_line_end = right_result.end();

    std::shared_ptr<std::set<line_no>> lines = std::make_shared<std::set<line_no>>();
    std::set_intersection(left_line_begin, left_line_end, right_line_begin, right_line_end, 
			 std::inserter(*lines, lines->begin()));

   return QueryResult(rep(), lines, left_result.get_file() );

}

QueryResult OrQuery::eval(const TextQuery &t) const{
   auto left_result = lhs.eval(t);
   return eval(t, left_result.get_file()->size());
}

QueryResult OrQuery::eval(const TextQuery &t, QueryResult::line_no line_limit) const{

    auto left_result = lhs.eval(t, line_limit), right_result = rhs.eval(t, line_limit);
    auto left_line_begin = left_result.begin(), left_line_end = left_result.end(),
	 right_line_begin = right_result.begin(), right_line_end = right_result.end();

    auto lines = std::make_shared<std::set<line_no>>(left_line_begin, left_line_end);
    lines->insert(right_line_begin, right_line_end);

    return QueryResult(rep(), lines, left_result.get_file());
}
#endif
