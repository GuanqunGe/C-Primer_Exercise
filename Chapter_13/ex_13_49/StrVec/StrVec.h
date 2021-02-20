#ifndef STRVEC_H
#define STRVEC_H

#include <memory>
#include <string>
#include <utility>  //to use std::move
#include <initializer_list>  //to use initializer_list
#include <stdexcept>
#include <algorithm>


class StrVec{
public:
    using size_type = size_t;

    //default constructor
    StrVec():elements(nullptr), first_free(nullptr), cap(nullptr){}

    StrVec(std::initializer_list<std::string> );
    //copy constructor
    StrVec(const StrVec&);
    //copy assignment
    StrVec &operator=(const StrVec &);

    //move constructor
    StrVec(StrVec&& ) noexcept;
    //move assignment
    StrVec& operator=(StrVec&& ) noexcept;

    //index operator
    std::string& operator[](size_t);
    const std::string& operator[](size_t) const;

    //destructor
    ~StrVec();

    void push_back(const std::string&);
    size_t size() const {return first_free - elements; }
    size_t capacity() const {return cap - elements; }
    void reserve(size_t);
    void resize(size_t n, const std::string &s="");

    std::string *begin() {return elements;}
    std::string *end() {return first_free; }
    const std::string *begin() const //to allow const StrVec object to use this function
    {return elements; }
    const std::string *end() const {return first_free; }
    const std::string *cbegin() const {return elements; }
    const std::string *cend() const {return first_free; }

    //inline std::string *begin() const; //even though this is not wrong, it does not follow our logic of 'constness' of object.
    //inline std::string *end() const;

private:
    /** data members **/
    static std::allocator<std::string> alloc;
    std::string *elements;
    std::string *first_free;
    std::string *cap;

    /** functions **/
    void free(); //free the memory used 
    void chk_n_alloc() //check if need to reallocate the memory space
    { if(first_free == cap) reallocate(); }

    void reallocate();
    void reallocate(size_t);
    std::pair<std::string*, std::string*> alloc_n_copy
	(const std::string*, const std::string*); 
};
#endif
