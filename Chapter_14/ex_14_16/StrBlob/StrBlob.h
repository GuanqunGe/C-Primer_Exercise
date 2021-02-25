#ifndef STRBLOB_H
#define STRBLOB_H

#include <vector>
#include <string>
#include <memory>
#include <initializer_list>
#include <stdexcept>
#include <utility>

class StrBlobPtr;

class StrBlob{
    friend class StrBlobPtr;
    friend class ConstStrBlobPtr;
    friend bool operator==(const StrBlob&, const StrBlob&);
    friend bool operator!=(const StrBlob&, const StrBlob&);
    friend bool operator<(const StrBlob&, const StrBlob&);
    friend bool operator>(const StrBlob&, const StrBlob&);
    friend bool operator<=(const StrBlob&, const StrBlob&);
    friend bool operator>=(const StrBlob&, const StrBlob&);
public:
    typedef std::vector<std::string>::size_type size_type;
    StrBlob();
    StrBlob( std::initializer_list<std::string> );

    //copy constructor
    StrBlob(const StrBlob&);

    //copy-assignment operator
    StrBlob& operator=(const StrBlob &);

    size_type size() const {return data->size(); }
    bool empty() const {return data->empty(); }

    //add and remove elemnt
    void push_back(const std::string & t) { data->push_back(t); }
    void push_back(std::string &&t) 
	{data->push_back( std::move(t) ); }  //need to use std::move,b/c even though t is rvalue reference, it is an lvalue
    void pop_back();

    //element access
    std::string &front();
    std::string &back();
    const std::string &front() const;
    const std::string &back() const;
    //subscript operator
    std::string &operator[](size_type);
    const std::string &operator[](size_type) const;

    StrBlobPtr begin();
    StrBlobPtr end();

private:
    std::shared_ptr<std::vector<std::string>> data;
   
    //throw msg if data[i] isn't valid
    void check(size_type i, const std::string &msg) const;
};

#endif
