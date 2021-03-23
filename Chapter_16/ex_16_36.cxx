template <typename T> void f1(T, T);
template <typename T1, typename T2> void f2(T1, T2);

// error
//template <typename T> f1(T, T);
//template <typaname T1, typename T2) f2(T1, T2);

int main(){
    int i = 0, j = 42, *p1 = &i, *p2 = &j;
    const int *cp1 = &i, *cp2 = &j;

    //despite the fact that f1 and f2 are declared in the wrong syntax.
    //(a)
    f1(p1, p2);  //instantiate void f1(int*, int*)

    //(b)
    f2(p1, p2);   //instantiate void f2(int*, int*), both T1, T2 -> int*

    //(c)
    f1(cp1, cp2);  //instantiate void f1(const int*, const int*), T1-> const int*, because it's low-level const.

    //(d)
    f2(cp1, cp2);  //instantiate void f2(const int*, const int*), both T1, T2 -> const int *

    //(e) 
    f1(p1, cp1);   // My answer:
		   // instantiate void f1(const int*, const int*), as template argument deduction allows conversion from 
		   // pointer to non-const object to pointer to const.
		   //
		   // The fact: compilation failed, due to the confliction of deduced template arguments
		   // "deduced conflicting types for parameter ‘T’ (‘int*’ and ‘const int*’)"
		   //
		   // I know why now... "Function argument" that is a reference/pointer to const can be passed reference/
		   // pointer to non-const. In this case, the function argument is just type T, not const T*.

    //(f)
    f2(p1, cp1);  //instantiate void f2(int*, const int*), as template f2 allows two different template arguments

    return 0;
}
