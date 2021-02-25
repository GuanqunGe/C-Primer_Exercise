#ifndef STRBLOBPTR_H
#define STRBLOBPTR_H

#include <vector>
#include <string>
#include <memory>
#include <stdexcept>
#include <cstddef> //to use ptrdiff_t

class StrBlob;

class StrBlobPtr{
    friend bool operator==(const StrBlobPtr&, const StrBlobPtr&);
    friend bool operator!=(const StrBlobPtr&, const StrBlobPtr&);
    friend bool operator<(const StrBlobPtr&, const StrBlobPtr&);
    friend bool operator>(const StrBlobPtr&, const StrBlobPtr&);
    friend bool operator<=(const StrBlobPtr&, const StrBlobPtr&);
    friend bool operator>=(const StrBlobPtr&, const StrBlobPtr&);
    friend ptrdiff_t operator-(const StrBlobPtr&, const StrBlobPtr&); 
public:
    //constructor
    StrBlobPtr():curr(0){}
    StrBlobPtr(StrBlob &a, size_t sz = 0);

    //dereference the wptr, grab the reference to curr element
    std::string &deref() const;
    // increment the curr
    StrBlobPtr& incr();

    //prefix-increment/decrement version
    StrBlobPtr& operator++();
    StrBlobPtr& operator--();
    //postfix-increment/decrement version
    StrBlobPtr operator++(int);
    StrBlobPtr operator--(int);

    StrBlobPtr& operator+=(size_t);
    StrBlobPtr& operator-=(size_t);
    StrBlobPtr operator+(size_t) const;
    StrBlobPtr operator-(size_t) const;

    std::string& operator*() const; //similar to deref()
    std::string* operator->() const;

    //about subscript operator
    //in my understanding, this class mimics the operation offered by iterators of vector, so I don't think 
    //it should have a subscript operator. Further more, even if we can add a subscript operator for this 
    //class, we can only add the non-const verion, and add the const version to the ConstStrBlobPtr class.
private:

    std::shared_ptr<std::vector<std::string>> check(std::size_t, const std::string &) const;
    std::weak_ptr<std::vector<std::string>> wptr;
    std::size_t curr;

};

#endif
