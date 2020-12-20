#include <iostream>
#include <iterator>

using std::cin;
using std::begin;
using std::end;
using std::cout;
using std::endl;

int main(){

    int element;
    int a[10]={}, b[7]={};  //define two empty arrays
    cout << "Please enter the elements for array a: (maximum 10 elements)" << endl;
    auto pa = a;

    //fill array a
    while(pa!=end(a) && cin >> element){
        *pa = element;
        pa++;
    }

    cout << "Please enter elements for aaray b: (maximum 7 elements):" << endl;
    auto pb = b;
    //fill array b
    while(pb != end(b) && cin >> element){
        *pb = element;
        pb++;
    }

  
    pa = a; pb = b; //assign pointers to point to the beginning of array
    while(pa != end(a) && pb!= end(b)){
        if(*pa > *pb){
            cout << "array a is larger than array b" << endl;
            return 0;
        }
        else if(*pa < *pb){
            cout << "array b is larger than array a " << endl;
            return 0;
        }else{
            pa++; 
	    pb++;
        }
    }

    if(pa == end(a) && pb == end(b)) cout << "two arrays are the same" << endl;
    else if(pa == end(a) && pb != end(b)) cout << "array b is alrger than array a" << endl;
    else cout << "array a is larger than array b" <<endl;

    return 0;
}
