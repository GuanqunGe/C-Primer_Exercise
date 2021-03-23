#include <iostream>

template <typename elemType> class ListItem; //forward declaration
template <typename elemType> class List{
public:
    List<elemType>();
    List<elemType>(const List<elemType> &);
    List<elemType>& operator=(const List<elemType> &);
    ~List();

    //ListItem is a class template, not a type, we need to provide the template arguments for it to be used as a type.
    //void insert(ListItem *ptr, elemType value);
    void insert(ListItem<elemType> *ptr, elemType value); 
private:
    //ListItem *front, *end;
    ListItem<elemType> *front, *end;
};

// we haven't defined these class members functions, but as long as we don't call them, the code should compile successfully.
int main(){
    return 0;
}
