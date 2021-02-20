#include "Folder.h"
#include "Message.h"

Folder::Folder(const Folder &f):fname(f.fname), messages(f.messages){
    add_messages();
}

Folder& Folder::operator=(const Folder &f){
    remove_messages();
    messages = f.messages;
    fname = f.fname;
    add_messages();
    return *this;
}

Folder::~Folder(){
    std::cout << "destruct " << fname << std::endl;
    remove_messages();

/*
    for(auto m : messages)
  	// m->remove(*this); //I don't think this will work as expected, because 'messages' is somehow modified
  			     //through addMsg function during the for loop
  			     //I'd prefer directly erase 'this' from the 'folders' member of each message
 	m->erase(this);
*/

}

void Folder::remove_messages(){
    for(auto m : messages)
        m->erase(this);
}

void Folder::add_messages(){
    for(auto m : messages)
        m->insert(this);
}
