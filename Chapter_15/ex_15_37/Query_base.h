#ifndef QUERY_BASE
#define QUERY_BASE

#include "TextQuery.h"
#include "QueryResult.h"
#include <string>

class Query_base{

    // don't know why we need a friend class Query
    // --> so that we can call the virtual rep() function and destructor of Query_base class through Query.
    // but why isn't Query also friend of the derived class??
    friend class Query;
    friend class OrQuery;
    friend class NotQuery;
    friend class AndQuery;
    friend class BinaryQuery;
protected:
    using line_no = TextQuery::line_no;
    virtual ~Query_base() = default;
private:
    virtual QueryResult eval(const TextQuery &) const = 0;
    virtual std::string rep() const = 0;
};
#endif
