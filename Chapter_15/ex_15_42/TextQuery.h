#ifndef TEXT_QUERY_H
#define TEXT_QUERY_H

#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <memory>

class QueryResult;

class TextQuery{
public:
    typedef std::vector<std::string>::size_type line_no;
    TextQuery(std::ifstream &);
    QueryResult query(const std::string &) const;
    QueryResult query(const std::string &, line_no) const;
private:
    std::shared_ptr<std::vector<std::string>> file;
    std::map<std::string, std::shared_ptr<std::set<line_no>>> word_map;
};
#endif
