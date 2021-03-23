#ifndef SHARED_POINTER_H
#define SHARED_POINTER_H

#include <functional>

template <typename T>
class SharedPtr{
    //typedef void DeleteFunc(T*); //typedef of deleter function
public:
    SharedPtr(): obj(nullptr), usr_count(nullptr), deleter(null_deleter){}

    //other constructor 
    //SharedPtr(T *p, DeleteFunc *fp = nullptr):obj(p), usr_count(new std::size_t(1)),deleter(fp){}

    // if I pass in an function object instead of function pointer?
    // obviously need to write another function, as there is no conversion from class object to function pointer
    //template <typename F>
    //SharedPtr(T *p, F f):obj(p), usr_count(new std::size_t(1)),deleter(f){}

    // final version !
    SharedPtr( T *p, std::function<void (T*)> f = null_deleter):obj(p), usr_count(new std::size_t(1)),deleter(f){}


    //need to define copy-control members
    SharedPtr(const SharedPtr &);
    SharedPtr(SharedPtr&&);
    SharedPtr &operator=(const SharedPtr &);
    SharedPtr &operator=(SharedPtr &&);
    ~SharedPtr();

    //interface
    bool unique() const{
	return usr_count && *usr_count == 1;
	//return (usr_count && *usr_count == 1) ? true : false;
    }

    std::size_t use_count() const{
	return usr_count ? *usr_count : 0;
    }

    void reset(T *p = nullptr, std::function<void (T*)> f = null_deleter);

    T* get() const {return obj;}
    T& operator*() const;
    T* operator->() const;
    operator bool() const { return usr_count; }
private:

    void chk_n_free();

    T *obj;
    std::size_t *usr_count;
    //DeleteFunc *deleter; //function pointer does not work for the case where deleter is a function object
    std::function<void (T*)> deleter; //default initialized as a null object

    static std::function<void(T*)> null_deleter;
    
};

template <typename T>
std::function<void(T*)> SharedPtr<T>::null_deleter = std::function<void(T*)>(nullptr);

// ----- copy control members ------
template <typename T>
SharedPtr<T>::SharedPtr(const SharedPtr &sp): obj(sp.obj), usr_count(sp.usr_count), deleter(sp.deleter){
    ++*usr_count;
}

template <typename T>
SharedPtr<T>::SharedPtr(SharedPtr &&sp):obj(sp.obj), usr_count(sp.usr_count), deleter(sp.deleter){
    sp.obj = nullptr; sp.usr_count = nullptr; sp.deleter = null_deleter;
}

template <typename T>
SharedPtr<T>& SharedPtr<T>::operator=(const SharedPtr &sp){
    ++*sp.usr_count;
    if(usr_count){
	--*usr_count;
	chk_n_free();
    }
    obj = sp.obj;
    usr_count = sp.usr_count;
    deleter = sp.deleter;
    return *this;
}

template <typename T>
SharedPtr<T> &SharedPtr<T>::operator=(SharedPtr &&sp){
    if(this != &sp){
	if(usr_count){
	    --*usr_count;
	    chk_n_free();
	}
	obj = sp.obj; usr_count = sp.usr_count; deleter = sp.deleter;
	sp.obj = nullptr; sp.usr_count = nullptr; sp.deleter = null_deleter;
	
    }
    return *this;
}

template <typename T>
SharedPtr<T>::~SharedPtr(){
    if(usr_count){
	--*usr_count;
	chk_n_free();
    }
}

// interface function
template <typename T>
T& SharedPtr<T>::operator*() const{
    if(!usr_count)
	throw std::runtime_error("dereference on a null pointer");
    return *obj;
}

template <typename T>
T* SharedPtr<T>::operator->() const{
   return obj; //for null shared_ptr case, error will be handled at (*bult-in pointer).mem() stage.
}

template <typename T>
void SharedPtr<T>::reset(T *p, std::function<void (T*)> f){
    if(usr_count){
	--*usr_count;
 	chk_n_free();
    }
    obj = p; 
    p ? usr_count = new std::size_t(1) : usr_count = nullptr;
    deleter = f;
}

//helper function
template <typename T>
inline void SharedPtr<T>::chk_n_free(){
    if(*usr_count == 0){
	//delete the object
	 deleter ? deleter(obj) : delete obj;
	//if(deleter)  deleter(obj);  //both work
	//else delete obj;

	//delete user count
	delete usr_count;
    }
}

#endif
