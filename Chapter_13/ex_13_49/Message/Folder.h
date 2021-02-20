#ifndef FOLDER
#define FOLDER

#include <set>
#include <string>
#include <iostream>
#include "Message.h"

using std::string;
using std::set;


class Folder{
    friend class Message;
public:
    Folder(const string &s=""): fname(s){};

    Folder(const Folder &);
    Folder(Folder &&);
    Folder &operator=(const Folder &);
    Folder &operator=(Folder &&);

    //destructor
    // Essential to remove pointers to Folders from Messages linked to it
    ~Folder();

    void addMsg(Message *pm){
	messages.insert(pm);
	std::cout << fname << ", insert " << pm << std::endl;
    }
    void remMsg(Message *pm){
	messages.erase(pm);
	std::cout << fname << ", remove " << pm << std::endl;
    }

private:
    string fname; //folder name
    set<Message*> messages;

    //helper function
    void remove_messages();
    void add_messages();
    void move_Messages(Folder*);
};
#endif
