#ifndef STRBLOBPTR_H
#define STRBLOBPTR_H

#include <vector>
#include <string>
#include <memory>
#include <stdexcept>

class StrBlob;

class StrBlobPtr{
public:
    //constructor
    StrBlobPtr():curr(0){}
    StrBlobPtr(StrBlob &a, size_t sz = 0);

    //dereference the wptr, grab the reference to curr element
    std::string &deref() const;
    // increment the curr
    StrBlobPtr& incr();
private:

    std::shared_ptr<std::vector<std::string>> check(std::size_t, const std::string &) const;
    std::weak_ptr<std::vector<std::string>> wptr;
    std::size_t curr;

};

#endif
