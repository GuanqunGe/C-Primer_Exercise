#ifndef CONST_STRBLOBPTR_H
#define CONST_STRBLOBPTR_H

#include <vector>
#include <string>
#include <memory>
#include <stdexcept>

class StrBlob;

class ConstStrBlobPtr{
    friend bool operator==(const ConstStrBlobPtr&, const ConstStrBlobPtr&);
    friend bool operator!=(const ConstStrBlobPtr&, const ConstStrBlobPtr&);
public:
    //constructor
    ConstStrBlobPtr():curr(0){}
    ConstStrBlobPtr( const StrBlob &a, size_t sz = 0);

    //dereference the wptr, grab the reference to curr element
    const std::string &deref() const;
    // increment the curr
    ConstStrBlobPtr& incr();

    const std::string& operator*() const;
    const std::string* operator->() const;
private:

    std::shared_ptr<std::vector<std::string>> check(std::size_t, const std::string &) const;
    std::weak_ptr<std::vector<std::string>> wptr;
    std::size_t curr;

};

#endif
