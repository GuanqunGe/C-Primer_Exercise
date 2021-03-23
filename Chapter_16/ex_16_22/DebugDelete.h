#ifndef DEBUG_DELETE_H
#define DEBUG_DELETE_H

#include <iostream>

class DebugDelete{
public:
    DebugDelete(std::ostream &s = std::cerr): os(s){}
    template <typename T> void operator()(T *p) const{
	os << "Delete pointer" << std::endl;
	delete p;
    }
private:
    std::ostream &os;
};

#endif
