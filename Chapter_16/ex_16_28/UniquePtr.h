#ifndef UNIQUE_POINTER_H
#define UNIQUE_POINTER_H

template <typename T>
void delete_wrapper(T *p){
    delete p;
}

template <typename T, typename F = void (*)(T*) >
class UniquePtr{
public:
    UniquePtr():obj(nullptr), func(delete_wrapper<T>){}
    // UniquePtr():obj(nullptr), func(delete_wrapper){}   
    // hmmm, I didn't specify the template argument for delete_wrapper, and the program still successfully compiled and ran..
    UniquePtr( T *p): obj(p), func(delete_wrapper<T>){}
    UniquePtr( T *p, F f): obj(p), func(f){}
    UniquePtr(F f):obj(nullptr), func(f){}

    //does not allow copy assignement
    UniquePtr(const UniquePtr &) = delete;
    UniquePtr& operator=(const UniquePtr &) = delete;

    //does allow move construction and move assignment
    UniquePtr(UniquePtr&&);
    UniquePtr& operator=(UniquePtr &&);

    ~UniquePtr(){
	if(obj) func(obj);
    }

    //interface function
    T* release(){
	T* temp = obj;
	obj = nullptr;
	return temp;
    }

    void reset(T *p = nullptr){
	if(obj) func(obj);
	obj = p;
    } 

    //convert unique pointer to bool
    operator bool() const {return obj;}
    T& operator*();
    T* operator->();
    T* get() {return obj;}
private:
    T *obj;
    F func;
};

template <typename T, typename F>
UniquePtr<T, F>::UniquePtr(UniquePtr &&up): obj(up.obj), func(up.func){
    up.obj = nullptr;
    //because we don't know if F is a function pointer or function object, can't do anything to up.func member, but, this is fine.
}

template <typename T, typename F>
UniquePtr<T, F>& UniquePtr<T,F>::operator=(UniquePtr &&up){
    if(this != &up){
	if(obj) func(obj); //or do reset()
	obj = up.obj; func = up.func;
  	up.obj = nullptr;
    }
    return *this;
}

template <typename T, typename F>
T& UniquePtr<T, F>::operator*(){
    if(!obj)
	throw std::runtime_error("dereference on a null unique_ptr");
    return *obj;
}

template <typename T, typename F>
T* UniquePtr<T, F>::operator->(){
    return obj;
}
#endif
