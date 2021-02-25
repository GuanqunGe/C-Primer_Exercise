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

StrBlobPtr &StrBlobPtr::operator++(){
    check(curr, "cursor out of range");
    ++curr;
    return *this;
}

StrBlobPtr &StrBlobPtr::operator--(){
    --curr;
    //note that, there is a reason why we put the check function after decrement
    //that is, to mimic pointer arithmetic
    //we should allow pointer to point to each element, and one pass the last element
    check(curr, "cursor out of range");
    return *this;
}

StrBlobPtr StrBlobPtr::operator++(int){
    StrBlobPtr temp = *this;
    ++(*this);
    return temp;
}

StrBlobPtr StrBlobPtr::operator--(int){
    StrBlobPtr temp = *this;
    --(*this);
    return temp;
}

StrBlobPtr &StrBlobPtr::operator+=(size_t n){
    for(size_t i = 0 ; i < n ; ++i){
	++*this;	
    }
    return *this;
}

StrBlobPtr &StrBlobPtr::operator-=(size_t n){
    for(size_t i =0; i < n; ++i)
	--(*this);
    return *this;
}

StrBlobPtr StrBlobPtr::operator+(size_t n) const{

    //if I do this, then it's actually different from pointer arithmetic
    //as I am not allowing pointer pointing to one pass the last element
    //check(curr+n, "destination is out of range");   


    //this method allows pointer to go beyong the last element
    StrBlobPtr temp = *this;
    temp += n; //use defined functions
	       //for similar reasons as addition in Sales_data, we should call += inside +.

    /*
    for(size_t i = 1; i < n + 1; ++i){
	++temp;
    } */
    return temp;   
}

StrBlobPtr StrBlobPtr::operator-(size_t n) const{
    StrBlobPtr temp = *this;
    temp -= n;
  
    /*
    for(size_t i = 0; i < n; ++i)
	--temp;
    */
    return temp;
}

ptrdiff_t operator-(const StrBlobPtr &lhs, const StrBlobPtr &rhs){
    ptrdiff_t diff;
    if(lhs.wptr.lock() == rhs.wptr.lock()){
	diff = static_cast<int>(lhs.curr) - static_cast<int>(rhs.curr);
    }
    return diff;
}


// == logical meaning for pointers: do two pointers point to the same memory
bool operator==(const StrBlobPtr &lhs, const StrBlobPtr &rhs){
    // weak_ptr doesn't have relational operator
    // shared_ptr has relational operator (that compares binding built-in operator)
    // logical AND has lower precedence than == operator
    return lhs.curr == rhs.curr && lhs.wptr.lock() == rhs.wptr.lock();

}


bool operator!=(const StrBlobPtr &lhs, const StrBlobPtr &rhs){
    return !(lhs == rhs);
}


// A bit uncertain how I should implement this..
// If two StrBloPtr do not point to the same StrBlob, neither will be less than the other, nor do they equal..
bool operator<(const StrBlobPtr &lhs, const StrBlobPtr &rhs){
    return lhs.wptr.lock() == rhs.wptr.lock() &&  lhs.curr < rhs.curr;
    
}

bool operator>(const StrBlobPtr &lhs, const StrBlobPtr &rhs){
    return rhs < lhs;
}


//need to be careful when defining <= and >=
//if < return false, doesn't mean >= should return true
bool operator<=(const StrBlobPtr &lhs, const StrBlobPtr &rhs){
    return lhs < rhs || lhs == rhs; //logical OR has the lowest precedence
}


bool operator>=(const StrBlobPtr &lhs, const StrBlobPtr &rhs){
    return lhs > rhs || lhs == rhs;
}

std::string& StrBlobPtr::operator*() const{
    auto sptr = check(curr, "dereference out of range");
    return (*sptr)[curr];
}

std::string* StrBlobPtr::operator->() const{
    //return &(*(*this));  //does this work?  YES!
    return & this->operator*();
}
