#ifndef TEXT_QUERY_H
#define TEXT_QUERY_H

#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <memory>
#include "../ex_13_39/StrVec.h" //to use StrVec::size_type

class QueryResult;
class StrVec;

class TextQuery{
public:
    typedef StrVec::size_type line_no;
    TextQuery(std::ifstream &);
    QueryResult query(const std::string &) const;
private:
    std::shared_ptr<StrVec> file;
    std::map<std::string, std::shared_ptr<std::set<line_no>>> word_map;
};
#endif
