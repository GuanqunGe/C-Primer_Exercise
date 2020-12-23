#include <string>

using std::string;

int main(){

    //initialization
    int i;
    double d;
    string s = "Hello World";
    const string *ps = &s;
    char *pc = "Wollows!";
    void *pv;

 
    //a: pv = (void*)ps;
    //pv = static_cast<void*>(ps);  //does not work, pointer of const can only be casted into a const void* pointer.
    pv = static_cast<void*>(const_cast<string*>(ps));

    //b: i = int(*Pc)
    i = static_cast<int>(*pc);

    //c: pv = &d;
    pv = static_cast<void*>(&d);

    //d: pc = (char*)pv;
    pc= static_cast<char*>(pv);

    return 0;
   
}
