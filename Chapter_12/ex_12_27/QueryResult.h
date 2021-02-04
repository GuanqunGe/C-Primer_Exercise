#ifndef QUERY_RESULT_H
#define QUERY_RESULT_H

#include <iostream>
#include <string>
#include <set>
#include <memory>
#include <vector>

class TextQuery;

class QueryResult{
public:
    QueryResult():count(0){}
    QueryResult(const std::string &s): word(s), count(0) {}
    QueryResult(const std::string &, const TextQuery &);

    const std::string &GetWord() const {return word; }
    unsigned GetCount() const {return count;}
    const std::set<unsigned> &GetLine() const { return line_number;}
    std::shared_ptr<std::vector<std::string>> GetContentPtr() const 
	{ return content; }

private:
    unsigned count;
    std::string word;
    std::set<unsigned> line_number;
    std::shared_ptr<std::vector<std::string>> content;
};

std::ostream &print(std::ostream &, const QueryResult &);
#endif
