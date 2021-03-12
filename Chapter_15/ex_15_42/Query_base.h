#ifndef QUERY_BASE_H
#define QUERY_BASE_H

#include "TextQuery.h"
#include "QueryResult.h"
#include <string>

class Query_base{

    // don't know why we need a friend class Query
    // --> so that we can call the virtual rep() function and destructor of Query_base class through Query.
    // but why isn't Query also friend of the derived class??
    friend class Query;

protected:
    using line_no = TextQuery::line_no; //so that derived class can use line_no as well
    virtual ~Query_base() = default;
private:
    virtual QueryResult eval(const TextQuery &) const = 0;
    virtual QueryResult eval(const TextQuery &, QueryResult::line_no) const = 0;
    virtual std::string rep() const = 0;
};
#endif
