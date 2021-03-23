#ifndef VEC_H
#define VEC_H

#include <memory>
#include <initializer_list>
#include <stdexcept>
#include <utility>

template <typename T>
class Vec{
public:
    Vec():elements(nullptr), first_free(nullptr), cap(nullptr){}
    Vec(size_t, const T&);
    Vec(std::initializer_list<T>);

    //need to define copy-control members
    Vec(const Vec&);
    Vec(Vec&&);
    Vec &operator=(const Vec&);
    Vec &operator=(Vec&&);
    ~Vec();

    //interface function
    size_t size() const {return first_free - elements;}
    size_t capacity() const { return cap - elements; }
    void push_back(const T&);
    void push_back(T&&);
    T &operator[](size_t); //index operator
    const T& operator[](size_t) const;

    template <typename... Args> void emplace_back(Args&&...);

    //iterator
    T* begin();
    T* end();
    const T* begin() const;
    const T* end() const;
private:
    static std::allocator<T> alloc;
    void chk_n_alloc() { 
	if(size() == capacity() ) reallocate();
    }
    std::pair<T*, T*> alloc_n_copy(const T*, const T*);
    void free();
    void reallocate();

    T* elements;   //points to first element
    T* first_free; //points to the one after the last element
    T* cap;        //points to one past the end of the memory
};

// define static member
template <typename T>
std::allocator<T> Vec<T>::alloc;

template <typename T>
Vec<T>::Vec(size_t n, const T &e){
    T* first = alloc.allocate(n);
    T* last = first;
    for(size_t i = 0; i!= n; ++i){
	alloc.construct(last++, e);
    }
    elements = first;
    first_free = cap = last;
}


template <typename T>
Vec<T>::Vec(std::initializer_list<T> lst){
    auto pair = alloc_n_copy(lst.begin(), lst.end());
    elements = pair.first;
    cap = first_free = pair.second;
}

template <typename T>
Vec<T>::Vec(const Vec<T> &v){
    auto pair = alloc_n_copy(v.elements, v.first_free);
    elements = pair.first;
    cap = first_free = pair.second;
}

template <typename T>
Vec<T>::Vec(Vec<T> &&v): elements(v.elements), first_free(v.first_free), cap(v.cap){
    v.elements = nullptr; v.first_free = nullptr; v.cap = nullptr;
}

template <typename T>
Vec<T> &Vec<T>::operator=(const Vec<T> &v){
    auto pair = alloc_n_copy(v.elements, v.first_free);
    free();
    elements = pair.first;
    cap = first_free = pair.second;
    return *this;
}

template <typename T>
Vec<T> &Vec<T>::operator=(Vec<T> &&v){
    if(this != &v){
	free();
	elements = v.elements;
   	first_free = v.first_free;
	cap = v.cap;
	 v.elements = nullptr; v.first_free = nullptr; v.cap = nullptr;
    }
    return *this;
}

template <typename T>
Vec<T>::~Vec(){
    free();
}

template <typename T>
void Vec<T>::push_back(const T &e){
    chk_n_alloc();
    alloc.construct(first_free++, e);
}

template <typename T>
void Vec<T>::push_back(T &&e){
    chk_n_alloc();
    alloc.construct(first_free++, std::move(e));
}

template <typename T>
template <typename... Args>
inline void Vec<T>::emplace_back(Args&&... rest){
    chk_n_alloc();
    alloc.construct(first_free++, std::forward<Args>(rest)...);
}

template <typename T>
T& Vec<T>::operator[](size_t n){
    if(n >= size()) 
	throw std::out_of_range("index out of range");
    return elements[n];
}

template <typename T>
const T& Vec<T>::operator[](size_t n) const{
    if(n >= size())
	throw std::out_of_range("index out of range");
    return elements[n];
}

template <typename T>
T* Vec<T>::begin(){
    return elements;
}

template <typename T>
T* Vec<T>::end(){
    return first_free;
}

template <typename T>
const T* Vec<T>::begin() const{
    return elements;
}

template <typename T>
const T* Vec<T>::end() const{
    return first_free;
}

// helper function
template <typename T>
std::pair<T*, T*> Vec<T>::alloc_n_copy(const T* begin, const T* end){
    size_t size = end - begin;
    T* first  = alloc.allocate(size);
    T* last = first;
    for(auto iter = begin; iter != end; ++iter){
	alloc.construct(last++, *iter);
    }
    return {first, last};
    //return {first, std::uninitialized_copy(begin, end, first);} //!! make life easier
}

template <typename T>
void Vec<T>::reallocate(){
    size_t current_size = size();
    size_t realloc_size = ( current_size == 0 ? 1 : 2*current_size);
    T* first_element = alloc.allocate(realloc_size);
    T* last_element = first_element;
    for(size_t i = 0; i!= current_size; ++i){
	alloc.construct(last_element++, std::move(elements[i]));
    }
    free();
    elements = first_element;
    first_free = last_element;
    cap = elements + realloc_size;
}

template <typename T>
void Vec<T>::free(){
    if(elements){
	for(auto iter = elements; iter != first_free; ++iter)
	    alloc.destroy(iter);
 	alloc.deallocate(elements, capacity());
    }
}
#endif
