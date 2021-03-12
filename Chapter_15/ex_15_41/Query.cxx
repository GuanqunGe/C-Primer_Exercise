#include "Query.h"
#include "Derived_query.h"

Query::Query(const std::string &s): q(new WordQuery(s)), usr_count(new unsigned(1)) {
}

Query::Query(const Query &query): q(query.q), usr_count(query.usr_count){
    ++*usr_count;
}

Query::Query(Query &&query): q(query.q), usr_count(query.usr_count){
    query.q = nullptr;
    query.usr_count = nullptr;
}

Query& Query::operator=(const Query &query){

    ++*query.usr_count; //to make sure this function works for self-assignment as well

    --*usr_count;
    if(*usr_count == 0){
	delete q;
	delete usr_count;
    }

    q = query.q;
    usr_count = query.usr_count;
    return *this;
}

Query& Query::operator=(Query &&query){
    if(this != &query){//handle self-assingment
	q = query.q;
	usr_count = query.usr_count;
	query.q = nullptr; query.usr_count = nullptr;
    }
    return *this;
}

Query::~Query(){
    if(q){
	if(--*usr_count == 0){
	    delete q;
	    delete usr_count;
 	}
    }
}


std::ostream &operator<<(std::ostream &os, const Query &q){

    return os << q.rep();
}


Query operator~(const Query &q){
    return new NotQuery(q);
}

Query operator|(const Query &lhs,  const Query &rhs){
    return new OrQuery(lhs, rhs, "|");
}

Query operator&(const Query &lhs, const Query &rhs){
    return new AndQuery(lhs, rhs, "&");
}
