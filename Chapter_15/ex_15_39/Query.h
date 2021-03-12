#ifndef QUERY_H
#define QUERY_H

#include <iostream>
#include <string>
#include "Query_base.h"
#include "TextQuery.h"
#include "QueryResult.h"

class Query{
    friend Query operator~(const Query &);
    friend Query operator|(const Query&, const Query&);
    friend Query operator&(const Query&, const Query&);
public:
    Query(const std::string &);

    //QueryResult eval(const TextQuery &t) const;
    QueryResult eval(const TextQuery &t) const { return q->eval(t); }
    std::string rep() const { 
	std::cout << "Query::rep() " << std::endl; 
	return q->rep(); }
private:
    Query(std::shared_ptr<Query_base> query): q(query) {
	std::cout << "Query(std::shared_ptr<Query_base> query)" << std::endl;
    }
    std::shared_ptr<Query_base> q;
};

std::ostream &operator<<(std::ostream &os, const Query &q);

#endif
