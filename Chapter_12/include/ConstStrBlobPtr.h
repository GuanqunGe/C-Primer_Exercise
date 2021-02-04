#ifndef CONST_STRBLOBPTR_H
#define CONST_STRBLOBPTR_H

#include <vector>
#include <string>
#include <memory>
#include <stdexcept>

class StrBlob;

class ConstStrBlobPtr{
public:
    //constructor
    ConstStrBlobPtr():curr(0){}
    ConstStrBlobPtr( const StrBlob &a, size_t sz = 0);

    //dereference the wptr, grab the reference to curr element
    std::string &deref() const;
    // increment the curr
    ConstStrBlobPtr& incr();
private:

    std::shared_ptr<std::vector<std::string>> check(std::size_t, const std::string &) const;
    std::weak_ptr<std::vector<std::string>> wptr;
    std::size_t curr;

};

#endif
