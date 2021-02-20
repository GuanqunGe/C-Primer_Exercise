#ifndef STRBLOB_H
#define STRBLOB_H

#include <vector>
#include <string>
#include <memory>
#include <initializer_list>
#include <stdexcept>

class StrBlobPtr;

class StrBlob{
    friend class StrBlobPtr;
    friend class ConstStrBlobPtr;
public:
    typedef std::vector<std::string>::size_type size_type;
    StrBlob();
    StrBlob( std::initializer_list<std::string> );
    size_type size() const {return data->size(); }
    bool empty() const {return data->empty(); }

    //add and remove elemnt
    void push_back(const std::string & t) { data->push_back(t); }
    void pop_back();

    //element access
    std::string &front();
    std::string &back();
    const std::string &front() const;
    const std::string &back() const;

    //ex_12_19
    StrBlobPtr begin();
    StrBlobPtr end();

private:
    std::shared_ptr<std::vector<std::string>> data;
   
    //throw msg if data[i] isn't valid
    void check(size_type i, const std::string &msg) const;
};

#endif
