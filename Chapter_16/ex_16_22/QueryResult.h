#ifndef QUERY_RESULT_H
#define QUERY_RESULT_H

#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <set>
#include "DebugDelete.h"

class QueryResult{
friend std::ostream &print( std::ostream &, const QueryResult &);
public:
    
    using line_no = std::vector<std::string>::size_type;

    QueryResult(const std::string &s=""):word(s), lines(new std::set<line_no>(), deleter), file(new std::vector<std::string>(), deleter){}


    // shared_pointer lines and file will use whatever deleter is used by the arguments
    QueryResult(const std::string &s, std::shared_ptr<std::set<line_no>> lpt, std::shared_ptr<std::vector<std::string>> fpt): word(s), lines(lpt),file(fpt){}

    std::set<line_no>::const_iterator begin() const;
    std::set<line_no>::const_iterator end() const;

    std::shared_ptr<std::vector<std::string>> get_file() const;
private:

    static DebugDelete deleter;

    std::string word;
    std::shared_ptr<std::set<line_no>> lines;
    std::shared_ptr<std::vector<std::string>> file;
};


std::ostream &print( std::ostream &, const QueryResult &);
#endif

