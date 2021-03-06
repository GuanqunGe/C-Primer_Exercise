#ifndef TEXT_QUERY_H
#define TEXT_QUERY_H

#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <memory>
#include "DebugDelete.h"

class QueryResult;

class TextQuery{
public:
    typedef std::vector<std::string>::size_type line_no;
    TextQuery(std::ifstream &);
    QueryResult query(const std::string &) const;
private:
    static DebugDelete deleter;
    std::shared_ptr<std::vector<std::string>> file;
    std::map<std::string, std::shared_ptr<std::set<line_no>>> word_map;
};

#endif
