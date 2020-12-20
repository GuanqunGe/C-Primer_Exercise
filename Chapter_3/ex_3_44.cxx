#include <iostream>

using std::cout;
using std::endl;

using int_array=const int[4]; //int_array is an alias of const int array of 4 elemnts

int main(){

    int ia[3][4]={ {1, 2 ,3, 4},
		   {5, 6, 7, 8},
		   {9, 10, 11, 12}};

  
    //print every element in ia
    //method 1, for loop, reference
    cout << "Method 1" << endl;
    for(int_array &row: ia){  //have to use a reference here, otherwise the compiler complains about "have to initialize an array using list initializer"
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
    for(int_array *prow = ia; prow != ia+3; prow++){
        for(const int *pcol = (*prow); pcol != (*prow)+4; pcol++)   //*prow is now an array of 4 const ints
	    cout << *pcol << " ";
	cout << endl;
    }

    return 0;
   
}
