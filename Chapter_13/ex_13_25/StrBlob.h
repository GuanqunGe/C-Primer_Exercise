/********************
 * We will need copy constructor to dynamically allocate another vector<string> which is 
 * initialized from the vector of string copied object points to.
 * We will need copy-assignment constructor to dynamicaly allocate another vector<string> whose value is same 
 * as the one 'data' member in the copied object points to, and then make 'data' member of the left-hand
 * operand to point to the newly allocated vector<string>
 * This class does not need a destructor because shared_ptr can itself handle the allocation/deallocation 
 * of dynamic memory nicely.
 */
#ifndef STRBLOB_H
#define STRBLOB_H

#include <vector>
#include <string>
#include <memory>
#include <initializer_list>
#include <stdexcept>

class StrBlobPtr;

class StrBlob{
    friend class StrBlobPtr;
    friend class ConstStrBlobPtr;
public:
    typedef std::vector<std::string>::size_type size_type;
    StrBlob();
    StrBlob( std::initializer_list<std::string> );

    //copy constructor
    StrBlob(const StrBlob&);

    //copy-assignment operator
    StrBlob& operator=(const StrBlob &);

    size_type size() const {return data->size(); }
    bool empty() const {return data->empty(); }

    //add and remove elemnt
    void push_back(const std::string & t) { data->push_back(t); }
    void pop_back();

    //element access
    std::string &front();
    std::string &back();
    const std::string &front() const;
    const std::string &back() const;

    //ex_12_19
    StrBlobPtr begin();
    StrBlobPtr end();

private:
    std::shared_ptr<std::vector<std::string>> data;
   
    //throw msg if data[i] isn't valid
    void check(size_type i, const std::string &msg) const;
};

#endif
