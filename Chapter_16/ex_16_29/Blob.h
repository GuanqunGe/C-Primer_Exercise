#ifndef BLOB_H
#define BLOB_H

#include <iostream>
#include <memory>
#include <initializer_list>
#include <vector>
#include <string>
#include <stdexcept>
#include "SharedPtr.h"

template <typename T> class BlobPtr;
template <typename> class Blob;

template <typename T>
bool operator==(const Blob<T>&, const Blob<T>&);

template <typename T>
bool operator!=(const Blob<T>&, const Blob<T>&);

template <typename T> 
class Blob{
    friend class BlobPtr<T>;
    friend bool operator==<T>(const Blob<T>&, const Blob<T>&);
    friend bool operator!=<T>(const Blob<T>&, const Blob<T>&);
public:
    //need ‘typename’ before ‘std::vector<T>::size_type’ because ‘std::vector<T>’ is a dependent scope
    typedef typename std::vector<T>::size_type size_type;
    Blob();
    Blob(std::initializer_list<T> );

    //object pointed by Iterator should be convertible to type T.
    template <typename Iterator> Blob(Iterator b, Iterator e);

    //no need to define copy-control members

    void push_back(const T&);
    void push_back(T&&);
    void pop_back();
    T& back();
    T& front();
    const T& back() const;
    const T& front() const;
    size_type size() const;
    bool empty() const;
    T& operator[](size_type);
    const T& operator[](size_type) const;
private:
    SharedPtr<std::vector<T>> data;
    void check(size_type i, const std::string &msg) const;
};

// for class templates, headers for templates typically include definitions as well as declarations
// I tried to compile with definitions included in another .cxx file, and the compiler doesn't seem to be able to find 
// the definition, thus compilation failed.

template <typename T>
Blob<T>::Blob(): data(new std::vector<T>()){}

template <typename T>
Blob<T>::Blob(std::initializer_list<T> lst):
        data(new std::vector<T>(lst)){}

template <typename T>
template <typename Iterator>
Blob<T>::Blob(Iterator b, Iterator e):
	data(new std::vector<T>(b, e)){}

template <typename T>
void Blob<T>::push_back(const T &t){
    data->push_back(t);
}

template <typename T>
void Blob<T>::push_back(T &&t){
    data->push_back(std::move(t));
}

template <typename T>
void Blob<T>::pop_back(){
    check(0, "pop_back on empty Blob");
    data->pop_back();
}

template <typename T>
T& Blob<T>::back(){
    check(0, "back on empty Blob");
    return data->back();
}

template <typename T>
T& Blob<T>::front(){
    check(0, "front on empty Blob");
    return data->front();
}

template <typename T>
const T& Blob<T>::back() const{
    check(0, "back on empty Blob");
    return data->back();
}

template <typename T>
const T& Blob<T>::front() const{
    check(0, "front on empty Blob");
    return data->front();
}

template <typename T>
typename Blob<T>::size_type Blob<T>::size() const{
    return data->size();
}

template <typename T>
bool Blob<T>::empty() const{
    return data->empty();
}

template <typename T>
T& Blob<T>::operator[](size_type i){
    check(i, "index out of range");
    return (*data)[i];
}

template <typename T>
const T& Blob<T>::operator[](size_type i) const{
    check(i, "index out of range");
    return (*data)[i];
}

template <typename T>
void Blob<T>::check(size_type i, const std::string &msg) const{
    if(i >= data->size())
        throw std::out_of_range(msg);
}
      
template <typename T>
bool operator==(const Blob<T> &lhs, const Blob<T> &rhs){
    return *lhs.data == *rhs.data;
}

template <typename T>
bool operator!=(const Blob<T> &lhs, const Blob<T> &rhs){
    return !(lhs == rhs);
}
#endif
