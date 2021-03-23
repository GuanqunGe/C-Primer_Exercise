#ifndef BLOB_PTR_H
#define BLOB_PTR_H

#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include "Blob.h"

template <typename T> class BlobPtr;

template <typename T>
bool operator==(const BlobPtr<T>&, const BlobPtr<T>&);

template <typename T>
bool operator!=(const BlobPtr<T>&, const BlobPtr<T>&);

template <typename T>
bool operator<(const BlobPtr<T>&, const BlobPtr<T>&);

template <typename T>
bool operator>(const BlobPtr<T>&, const BlobPtr<T>&);

template <typename T>
class BlobPtr{
    friend bool operator==<T>(const BlobPtr<T>&, const BlobPtr<T>&);
    friend bool operator!=<T>(const BlobPtr<T>&, const BlobPtr<T>&);
    friend bool operator< <T>(const BlobPtr<T>&, const BlobPtr<T>&);
    friend bool operator> <T>(const BlobPtr<T>&, const BlobPtr<T>&);
public:
    typedef typename std::vector<T>::size_type size_type;

    BlobPtr();
    BlobPtr(Blob<T> &, size_type=0);
 
    //no need for copy-control members

    T& operator*() const;

    BlobPtr& operator++(); //prefix increment/decrement
    BlobPtr& operator--();

    BlobPtr operator++(int); //postfix increment/decrement
    BlobPtr operator--(int);
        
private:
    std::shared_ptr<std::vector<T>> check(size_type i, const std::string &msg) const;
    std::weak_ptr<std::vector<T>> wptr;
    size_type curr;
};

template <typename T>
BlobPtr<T>::BlobPtr(): curr(0){}

template <typename T>
BlobPtr<T>::BlobPtr( Blob<T> &a, size_type sz):wptr(a.data), curr(sz){}

template <typename T>
T& BlobPtr<T>::operator*() const{
    auto ptr = check(curr, "index out of range");
    return (*ptr)[curr]; 
}

template <typename T>
BlobPtr<T>& BlobPtr<T>::operator++(){
    check(curr, "index out of range");
    ++curr;
    return *this;
}

template <typename T>
BlobPtr<T>& BlobPtr<T>::operator--(){
    --curr;
    check(curr, "index out of range");
    return *this;
}
 
template <typename T>
BlobPtr<T> BlobPtr<T>::operator++(int){
    BlobPtr temp = *this;
    ++*this; //use the prefix version!!!
    return temp;
}

template <typename T>
BlobPtr<T> BlobPtr<T>::operator--(int){
    BlobPtr temp = *this;
    --*this;
    return temp;
}

template <typename T>
std::shared_ptr<std::vector<T>> BlobPtr<T>::check(size_type i, const std::string &msg) const{
    std::shared_ptr<std::vector<T>> ptr = wptr.lock();
    if(!ptr)
	throw std::runtime_error("Blob does not exist");
    if(i >= ptr->size())
	throw std::out_of_range(msg);
    return ptr;
}

template <typename T>
bool operator==(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs){
    auto lhs_ptr = lhs.wptr.lock();
    auto rhs_ptr = rhs.wptr.lock();
    return lhs_ptr == rhs_ptr && lhs.curr == rhs.curr;
}

template <typename T>
bool operator!=(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs){
    return !(lhs == rhs);
}

template <typename T>
bool operator<(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs){
    auto lhs_ptr = lhs.wptr.lock();
    auto rhs_ptr = rhs.wptr.lock();
    return lhs_ptr && rhs_ptr && lhs_ptr == rhs_ptr && lhs.curr < rhs.curr;
}

template <typename T>
bool operator>(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs){
    auto lhs_ptr = lhs.wptr.lock();
    auto rhs_ptr = rhs.wptr.lock();
    return lhs_ptr && rhs_ptr && lhs_ptr == rhs_ptr && lhs.curr > rhs.curr;
}

#endif
