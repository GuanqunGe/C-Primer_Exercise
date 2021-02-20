#include "StrVec.h"

std::allocator<std::string> StrVec::alloc;

//copy constructor
//value-like behavior
StrVec::StrVec(const StrVec &sv){

    auto pair = alloc_n_copy(sv.begin(), sv.end());
    elements = pair.first;
    first_free = cap = pair.second;
}

//list initializer
StrVec::StrVec(std::initializer_list<std::string> il){
    auto pair = alloc_n_copy(il.begin(), il.end());
    elements = pair.first;
    cap = first_free = pair.second;
}

//copy assignment
StrVec &StrVec::operator=(const StrVec &sv){
    auto pair = alloc_n_copy(sv.begin(), sv.end());
    free();
    elements = pair.first;
    first_free = cap = pair.second;
    return *this;
}

//index operator
std::string& StrVec::operator[](size_t n){
    if( n < size())
	return *(elements + n);
    else
	throw std::out_of_range("Accessing out-of-range element");
}

const std::string& StrVec::operator[](size_t n) const{
    if( n < size() )
	return *(elements + n );
    else
	throw std::out_of_range("Accessing out-of-range element");
}

void StrVec::free(){
    if(elements){
	//method 1 - to destroy the object in the memory
  	std::for_each(elements, first_free, [](std::string &s){alloc.destroy(&s); } );

 	//method 2 - to destroy the object inthe memory
    	//for(auto iter = elements; iter != first_free; )
	//    alloc.destroy(iter++);
 
        //can not pass a nullptr to deallocate, so we use an if statement
    	alloc.deallocate(elements, capacity());
    }
}

StrVec::~StrVec(){
    free();
}

void StrVec::push_back(const std::string &s){
    chk_n_alloc(); //check and reallocate space if necessary
    alloc.construct(first_free++, s);
}


void StrVec::reallocate(){
    size_t realloc_size = size() ? 2*size() : 1;
    reallocate(realloc_size);
}

void StrVec::reallocate(size_t n){
    //have to make sure n is larger than current size()

    auto pstart = alloc.allocate(n);
    auto iter = pstart;
    for(auto cp = elements; cp != first_free;  )
	alloc.construct(iter++, std::move(*cp++));

    free(); //need to free the old space before pointers are redirected to the new memory space
    elements = pstart;
    first_free = iter;
    cap = elements + n;
}


std::pair<std::string*, std::string*> StrVec::alloc_n_copy
(const std::string* b, const std::string *e){
    size_t length = e - b;
    std::string *pstart = alloc.allocate(length);
    return {pstart, std::uninitialized_copy(b, e, pstart) };
}


void StrVec::reserve(size_t n){
    if(n > capacity()){
 	reallocate(n);	
    }
}


void StrVec::resize(size_t n, const std::string &s){
    if( n > capacity()){
	reallocate(n);
 	std::uninitialized_fill(first_free, elements + n, s);
    }else if( n >= size()){
	std::uninitialized_fill(first_free, elements + n , s);
    }else{
	for(auto iter = elements + n; iter != first_free; )
	    alloc.destroy(iter++);
    }
    first_free = elements + n;
}


//inline function should be defined in the same header as the corresponding class definition!!!
/*
inline
std::string *StrVec::begin(){
    return elements;
}

inline
std::string *StrVec::end(){
    return first_free;
}

inline const std::string *StrVec::begin() const{
    return elements;
}

inline const std::string *StrVec::end() const{
    return first_free;
}

inline 
const std::string *StrVec::cbegin() const{
    return elements;
}

inline 
const std::string *StrVec::cend() const{
    return first_free;
}

*/
