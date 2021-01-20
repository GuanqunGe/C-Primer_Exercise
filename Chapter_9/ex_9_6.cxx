#include <list>
using std::list;

int main(){
    list<int> lst1;
    list<int>::iterator iter1 = lst1.begin(),
			iter2 = lst1.end();
    while( iter1 != iter2 ) /* .. */ 
    //while( iter1 < iter2 ) /* ... */  //iterator of list doesn't support <, <=, >, >= operators

    return 0;
}
