#include "Message.h"
#include "Folder.h"

Message::Message(const Message &m):contents(m.contents), folders(m.folders){
    add_to_Folders(m);
}

Message::Message(Message &&m):
   contents(std::move(m.contents))
{
 
    move_Folders(&m);

}

Message &Message::operator=(const Message &m){
    remove_from_Folders();
    contents = m.contents;
    folders = m.folders;
    add_to_Folders(m);
    return *this;
}

Message& Message::operator=(Message &&m){
    if(this != &m){
    	remove_from_Folders();
    	contents = std::move(m.contents);
	move_Folders(&m);
    }
    return *this;
}

Message::~Message(){
    std::cout << "destruct message: " << contents << std::endl;
    remove_from_Folders();
    std::cout << "finish destruct message: " << contents << std::endl;
}

void Message::move_Folders(Message *m){
   folders = std::move(m->folders);
    for( auto pf: folders){
        pf->remMsg(m);
        pf->addMsg(this); //adding element to container requires memory allocation, thus this statmenet might throw an exception
    }
    m->folders.clear(); //this is essential, as what's left in m.folders might be some garbage pointers, which probably don't even point to object of type Folder! (We don't know anything about the status of m.folders, so might as well consider the worse case.)
}

void Message::save(Folder &f){
    folders.insert(&f);
    f.addMsg(this);
}

void Message::remove(Folder &f){
    folders.erase(&f);
    f.remMsg(this);
}

void Message::add_to_Folders(const Message &m){
    for(auto &f : m.folders)
	f->addMsg(this);
}

void Message::remove_from_Folders(){
    for(auto &f : folders)
	f->remMsg(this);
}

void Message::insert(Folder* pf){
    folders.insert(pf);
}

void Message::erase(Folder* pf){
    folders.erase(pf);
}

void swap(Message &lhs, Message &rhs){
    std::cout << "swap two messages" << std::endl;
    lhs.remove_from_Folders();
    rhs.remove_from_Folders();

    using std::swap;
    swap(lhs.contents, rhs.contents);
    swap(lhs.folders, rhs.folders);

    lhs.add_to_Folders(lhs);
    rhs.add_to_Folders(rhs);
}
