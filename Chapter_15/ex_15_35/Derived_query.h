#ifndef DERIVED_QUERY_H
#define DERIVED_QUERY_H

#include "Query_base.h"
#include "QueryResult.h"
#include "TextQuery.h"
#include "Query.h"
#include <string>

class WordQuery : public Query_base{
    friend class Query;
    WordQuery(const std::string &s): query_word(s) {
	std::cout << "WordQuery(const std::string &s)" << std::endl;
    }
    QueryResult eval(const TextQuery &t) const { return t.query(query_word); }
    std::string rep() const { 
	std::cout << "WordQuery::rep()" << std::endl;
	return query_word; }
    std::string query_word;
};

class NotQuery : public Query_base{
    friend Query operator~(const Query &);
    NotQuery(const Query &q) : query(q) {
	std::cout << "NotQuery(const Query&)" << std::endl;
    }
    QueryResult eval(const TextQuery &t) const;
    std::string rep() const { 
	std::cout << "NotQuery::rep()" << std::endl;
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
	std::cout << "BinaryQuery::rep() " << std::endl;
	return "(" + lhs.rep() + " " + opSym + " " + rhs.rep() + ")";
    }
    Query lhs, rhs;
    std::string opSym; //operator symbol
};

class AndQuery : public BinaryQuery{
    friend Query operator&(const Query&, const Query&);
    AndQuery(const Query &l, const Query &r, const std::string &s):
	BinaryQuery(l, r, s){
	std::cout << "AndQuery(const Query &l, const Query &r, const std::string &s)" << std::endl;
    }
    QueryResult eval(const TextQuery &t) const;
};

class OrQuery : public BinaryQuery{
    friend Query operator|(const Query&, const Query&);
    OrQuery(const Query &l, const Query &r, const std::string &s):
	BinaryQuery(l, r, s){
	std::cout << "OrQuery(const Query &l, const Query &r, const std::string &s)" << std::endl;
    }
    QueryResult eval(const TextQuery &t) const;
};

//temporary definition, so that code compiles
QueryResult NotQuery::eval(const TextQuery &t) const{
    return query.eval(t);
}

QueryResult AndQuery::eval(const TextQuery &t) const{
    return lhs.eval(t);
}

QueryResult OrQuery::eval(const TextQuery &t) const{
    return lhs.eval(t);
}
#endif
