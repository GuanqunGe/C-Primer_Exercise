#include <iostream>

using std::cout;
using std::endl;

int main(){

    int ia[3][4]={ {1, 2 ,3, 4},
		   {5, 6, 7, 8},
		   {9, 10, 11, 12}};

  
    //print every element in ia
    //method 1, for loop, reference
    cout << "Method 1" << endl;
    for(const int (&row)[4] : ia){  //have to use a reference here.
	for(const int &col : row){
	    cout << col << " ";
	}
        cout << endl;
    }


    //method 2, regular subscripts
    cout << "Method 2" << endl;
    for(size_t i =0; i<3; i++){
        for(size_t j=0; j<4; j++)
	    cout << ia[i][j] << " ";
        cout << endl;
    }


    //method 3, for loop, use pointers
    cout << "Method 3" << endl;
    for(const int (*prow)[4] = ia; prow != ia+3; prow++){
        for(const int *pcol = (*prow); pcol != (*prow)+4; pcol++)   //*prow is now an array of 4 const ints
	    cout << *pcol << " ";
	cout << endl;
    }

    return 0;
   
}
