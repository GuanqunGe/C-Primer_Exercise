#include "Query.h"
#include "Derived_query.h"

Query::Query(const std::string &s): q(new WordQuery(s)) {
    std::cout << "Query::Query(const std::string &s)" << std::endl;
}

std::ostream &operator<<(std::ostream &os, const Query &q){

    return os << q.rep();
}


Query operator~(const Query &q){
    return std::shared_ptr<Query_base>(new NotQuery(q));
}

Query operator|(const Query &lhs,  const Query &rhs){
    return std::shared_ptr<Query_base>(new OrQuery(lhs, rhs, "|"));
}

Query operator&(const Query &lhs, const Query &rhs){
    return std::shared_ptr<Query_base>(new AndQuery(lhs, rhs, "&"));
}
