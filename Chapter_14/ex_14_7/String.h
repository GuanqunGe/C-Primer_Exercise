#ifndef STRING_H
#define STRING_H

//String class should be value-like
//String class should be like the StrVec, except that it holds chars
#include <memory>
#include <iostream>

class String{
    friend std::ostream &operator<<(std::ostream&, const String &);   
public:
    // constructors
    String(): start(nullptr), end(nullptr), cap(nullptr){}
    String(const char*);
    String(const String &);
    String(size_t, char);

    //copy assignment
    String& operator=(const String&);

    //move constructor
    String(String&& ) noexcept;
    //move assignment
    String& operator=(String&& ) noexcept;

    //destructor
    ~String();

    //common functions
    void push_back(char);
    size_t size() const {return end - start; }
    size_t capacity() const {return cap - start; }
    bool empty() const {return start == end; }
private:
    /** data member **/
    static std::allocator<char> alloc;
    char *start;
    char *end;
    char *cap;

    /** function **/
    void free();
    std::pair<char*, char*> alloc_n_copy(const char*, const char*);
    void reallocate();
};

#endif
