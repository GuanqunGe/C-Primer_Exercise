#include "StrBlob.h"
#include "ConstStrBlobPtr.h"

ConstStrBlobPtr::ConstStrBlobPtr(const StrBlob &a, size_t sz): wptr(a.data), curr(sz){}

std::shared_ptr<std::vector<std::string>> ConstStrBlobPtr::check(std::size_t sz, const std::string &msg) const{

    std::shared_ptr<std::vector<std::string>> sptr = wptr.lock();
    if( !sptr)
	throw std::runtime_error("ConstStrBlobPtr points to non-existent object");
    if(sz >= sptr->size())  //note that sz is size_t type, so it's non-negative
	throw std::out_of_range(msg);

    return sptr;
}


const std::string &ConstStrBlobPtr::deref() const{
    auto sptr = check(curr, "dereference out of range");
    //can not use weak_ptr to directly access the object
    return sptr->at(curr);
}

ConstStrBlobPtr& ConstStrBlobPtr::incr(){
    check(curr, "increment out of range");
    ++curr;
    return *this;
}

bool operator==(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs){
    return lhs.curr == rhs.curr && lhs.wptr.lock() == rhs.wptr.lock();
}


bool operator!=(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs){
    return !(lhs == rhs);
}

const std::string &ConstStrBlobPtr::operator*() const{
    auto sptr = check(curr, "derefence out of range");
    return (*sptr)[curr];
}

const std::string* ConstStrBlobPtr::operator->() const{
    return & this->operator*();
}
