#include "Folder.h"
#include "Message.h"

Folder::Folder(const Folder &f):fname(f.fname), messages(f.messages){
    add_messages();
}

Folder::Folder(Folder &&f): fname(std::move(f.fname)){
   move_Messages(&f); //require memory allocation
}

Folder& Folder::operator=(const Folder &f){
    remove_messages();
    messages = f.messages;
    fname = f.fname;
    add_messages();
    return *this;
}

Folder& Folder::operator=(Folder &&f){
    if(this != &f){
	remove_messages();
    	fname = std::move(f.fname);
    	move_Messages(&f);
    }
    return *this;
}

void Folder::move_Messages(Folder* pf){
    messages = std::move(pf->messages);
    for( auto m : messages){
	m->erase(pf); //necessary as well, otherwise the destructor of Message might run into trouble if Folder 'f' is deleted after this
	m->insert(this);
    }
    pf->messages.clear(); //necessary, as messaged will be used in destructor   
   
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
