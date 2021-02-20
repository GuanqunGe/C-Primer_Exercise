#ifndef MESSAGE
#define MESSAGE

#include <string>
#include <set>
#include <iostream>

using std::string;
using std::set;

class Folder;
class Message{
    friend class Folder;
    friend void swap(Message &, Message &);
public:

    //default constructor
    explicit Message(const string &s=""):contents(s){}

    //copy constructor
    Message(const Message &m);

    //copy assignment
    Message &operator=(const Message&);

    //destructor
    ~Message();

    //add/remove message to a folder
    void save(Folder&);
    void remove(Folder&);

    //insert/erase a pointer to folder, without modifying underlying Folder object
    //with these two functions, we can destruct or copy a folder!
    void insert(Folder*);
    void erase(Folder*);
private:
    string contents;
    set<Folder*> folders;

    void add_to_Folders(const Message&);
    void remove_from_Folders(); 
};

//void swap(Message &, Message &);

#endif
