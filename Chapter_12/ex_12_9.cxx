#include <memory>

int main(){

    int *q = new int(42), *r = new int(100);  //r and q point to two dynamically allocated objects
    r = q;  //r now point to the same dynamically allocated object as q does
	    //dynamic memory r previously points to is not freed, ie leaked
    


    auto q2 = std::make_shared<int>(42), r2 = std::make_shared<int>(100); //r2 and q2 point to two dynamically allocated objects
    r2 = q2; //r2 now points to the same object as q2 did, use count of object q2 points to is now 2
	     //use count of object r2 previouly points to is 0, thus it's destroyed and memory is freed


}
