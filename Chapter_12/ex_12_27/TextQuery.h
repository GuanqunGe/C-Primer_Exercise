#ifndef TEXT_QUERY_H
#define TEXT_QUERY_H

#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <sstream>
#include <memory>

class QueryResult;

class TextQuery{
public:
    typedef std::vector<std::string>::size_type size_type;
    TextQuery(): content(std::make_shared<std::vector<std::string>>()) {}
    TextQuery( std::ifstream &);
    QueryResult query(const std::string &) const;

    std::shared_ptr<std::vector<std::string>> GetContent() const {return content; }

    const std::map<std::string, std::multiset<unsigned>> &GetMap() const {return word_map;}

private:
    std::shared_ptr<std::vector<std::string>> content;
    std::map< std::string, std::multiset<unsigned>> word_map;
};
#endif
