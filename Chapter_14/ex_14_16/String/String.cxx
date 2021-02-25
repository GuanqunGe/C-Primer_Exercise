#include "String.h"
#include <iostream>
#include <utility>  //to use std::move

std::allocator<char> String::alloc;

String::String(const char* pc){
    //string does not include '\0' character, while C-string does
    const char* iter = pc;
    while(iter && *iter){ //move iter forward until it points to the '\0' character
        //need to be careful with the case where pc is nullptr
	//std::cout << *iter << " "; 
	++iter;
    }  
    auto pair = alloc_n_copy(pc, iter);
    start = pair.first;
    cap = end = pair.second;

}

String::String(const String &s){
    std::cout << "Running copy constructor" << std::endl;
    auto pair = alloc_n_copy(s.start, s.end);
    start = pair.first;
    cap = end = pair.second;
}

String::String(String &&s) noexcept :
  start(s.start), end(s.end), cap(s.cap){
    std::cout << "Running move constructor" << std::endl;
    s.start = s.end = s.cap = nullptr;
}

String::String(size_t n, char c){
    auto pc = alloc.allocate(n);
    start = pc;
    cap = end = std::uninitialized_fill_n(pc, n, c);
}

String& String::operator=(const String &s){
    std::cout << "Running copy assignment" << std::endl;
    //do the copy first
    auto pair = alloc_n_copy(s.start, s.end);
    //then do free
    free();
    //last do assignment
    start = pair.first;
    cap = end = pair.second;
    return *this;
}

//move assignment
String &String::operator=(String &&s) noexcept{
    std::cout << "Running move assignment" << std::endl;
    //check for self-assignment
    if(this != &s){
	free();
	start = s.start;
	end = s.end;
	cap = s.cap;
 	s.start = s.end = s.cap = nullptr;
    }
    return *this;
}

String::~String(){
    free();
}

void String::push_back(char c){
    if(size() == capacity()) reallocate();
    alloc.construct(end++, c);
}

char &String::operator[](size_t n){
    check(n); // check if n is out of range.
    return *(start+n);
    // return start[n];
}

const char &String::operator[](size_t n) const{
    check(n);
    return *(start+n);
}

void String::free(){
    if(start){
	for(auto p = end; p!= start; )
	    alloc.destroy(--p);
        alloc.deallocate(start, capacity());
    }
}

std::pair<char*, char*> String::alloc_n_copy(const char *b, const char *e){
    size_t length = e - b;
    auto pstart = alloc.allocate(length);
    auto pend = std::uninitialized_copy(b, e, pstart);
    return {pstart, pend};
}

void String::reallocate(){
    size_t length = size() ? 2*size() : 1;
    auto pstart = alloc.allocate(length);

    //method 1, copy construct
    //auto pend = std::uninitialized_copy(start, end, pstart);
    
    // method 2, use std::move to avoid copy construct
    // instead, directly transfer the ownership
    auto pend = pstart;
    for(auto iter = start; iter != end; )
	alloc.construct(pend++, std::move(*iter++));

    free();
    start = pstart;
    end = pend;
    cap = start + length;
}

bool operator==(const String &lhs, const String &rhs){
    if(lhs.size() != rhs.size()) return false;
    for(auto li = lhs.start, ri = rhs.start; li!= lhs.end && ri!= rhs.end; ++li, ++ri)
	if(*li != *ri) return false;
    return true;
}

bool operator!=(const String &lhs, const String &rhs){
    return !(lhs == rhs);
}

bool operator<(const String &lhs, const String &rhs){
    auto li = lhs.start, ri = rhs.start;
    for( ; li!=lhs.end && ri!=rhs.end; ++li, ++ri){
	if( *li < *ri) return true;
	else if( *li > *ri) return false;
    }
    if(li == lhs.end && ri != rhs.end) return true;
    else return false;
}

bool operator>(const String &lhs, const String &rhs){
    return lhs!= rhs && !(lhs < rhs);
}

bool operator<=(const String &lhs, const String &rhs){
    return !(lhs > rhs);
}

bool operator>=(const String& lhs, const String &rhs){
    return !(lhs < rhs);
}
void String::check(size_t n) const{
    if( n >= size() )
        throw std::out_of_range("index out of range");
}
