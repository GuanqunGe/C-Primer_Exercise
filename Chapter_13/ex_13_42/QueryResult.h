#ifndef QUERY_RESULT_H
#define QUERY_RESULT_H

#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <set>
#include "../ex_13_39/StrVec.h" //need to include this, b/c QueryResult uses member of StrVec


class QueryResult{
friend std::ostream &print( std::ostream &, const QueryResult &);
public:
    
    using line_no = StrVec::size_type;

    QueryResult(const std::string &s=""):word(s), lines(std::make_shared<std::set<line_no>>()), file(std::make_shared<StrVec>()){}
    QueryResult(const std::string &s, std::shared_ptr<std::set<line_no>> lpt, std::shared_ptr<StrVec> fpt): word(s), lines(lpt), file(fpt){}
private:
    std::string word;
    std::shared_ptr<std::set<line_no>> lines;
    std::shared_ptr<StrVec> file;
};

std::ostream &print( std::ostream &, const QueryResult &);
#endif

