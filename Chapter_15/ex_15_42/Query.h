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
    QueryResult eval(const TextQuery &t, QueryResult::line_no line_limit) const { return q->eval(t, line_limit); }
    std::string rep() const { 
	return q->rep(); }
private:
    Query(std::shared_ptr<Query_base> query): q(query) {
    }
    std::shared_ptr<Query_base> q;
};

std::ostream &operator<<(std::ostream &os, const Query &q);

#endif
