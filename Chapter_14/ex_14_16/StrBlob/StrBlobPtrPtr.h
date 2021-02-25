#ifndef STRBLOBPTRPTR_H
#define STRBLOBPTRPTR_H

#include <stdexcept>

class StrBlobPtr;

class StrBlobPtrPtr{
public:
    StrBlobPtrPtr()=default;
    StrBlobPtrPtr( StrBlobPtr &sp): pt(&sp){}

    StrBlobPtr* operator->() const;
private:
    StrBlobPtr* pt = nullptr;
};


StrBlobPtr* StrBlobPtrPtr::operator->() const{
    if(!pt)
	throw std::runtime_error("pointer is null");
    return pt;
}

#endif
