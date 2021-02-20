#include "StrBlob.h"
#include "StrBlobPtr.h"

StrBlobPtr::StrBlobPtr(StrBlob &a, size_t sz): wptr(a.data), curr(sz){}

std::shared_ptr<std::vector<std::string>> StrBlobPtr::check(std::size_t sz, const std::string &msg) const{

    std::shared_ptr<std::vector<std::string>> sptr = wptr.lock();
    if( !sptr)
	throw std::runtime_error("StrBlobPtr points to non-existent object");
    if(sz >= sptr->size())  //note that sz is size_t type, so it's non-negative
	throw std::out_of_range(msg);

    return sptr;
}


std::string &StrBlobPtr::deref() const{
    auto sptr = check(curr, "dereference out of range");
    //can not use weak_ptr to directly access the object
    return sptr->at(curr);
}

StrBlobPtr& StrBlobPtr::incr(){
    check(curr, "increment out of range");
    ++curr;
    return *this;
}

