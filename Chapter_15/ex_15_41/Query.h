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
	return q->rep(); }

    //now we are handling dynamic memory using built-in pointers, we need to define copy-control members
    Query(const Query &);
    Query(Query &&);
    Query &operator=(const Query &);
    Query &operator=(Query &&);
    ~Query();

private:

    //NOTE the pointer used in the following constructor must transfer the
    //ownership of the underlying object to this newly constructed object. Thus
    //an rvalue reference is used. Otherwise, that pointer (argument) may
    //become dangling pointer.
    //refering to https://github.com/jaege/Cpp-Primer-5th-Exercises/blob/master/ch15/15.41/Query.h 
    //
    //This is a really good point!!!
    //But considering that the only class that can use derived class from Query_base is Query class
    //as long as we handle the Query_base* pointer correctly within Query class, this implementation of 
    //Query constructor should be fine as well.
    Query( Query_base* query): q(query), usr_count(new unsigned(1)) {
    }

    Query_base* q;
    unsigned* usr_count; //user count of the Query_base object q points to
};

std::ostream &operator<<(std::ostream &os, const Query &q);

#endif
