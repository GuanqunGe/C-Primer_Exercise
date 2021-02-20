
class Point{
};

Point global;
Point foo_bar(Point arg){  //copy initialization of the parameter

    //copy initilaization of 'local'
    //copy initilaization of pointer to Point class 'heap' 
    // I believe the dynamically created Point object is initialized directly. (use to parentheses)
    Point local = arg, *heap = new Point(global);

    *heap = local;
    Point pa[4] = {local, *heap}; //copy constructor of element type in the array

    return *heap; //copy constructor for the temporary returned object
}


int main(){

    return 0;
}
