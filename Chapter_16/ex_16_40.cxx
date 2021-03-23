template <typename It>
auto fcn3(It beg, It end) -> decltype( *beg + 0)
{
    return *beg;
}

// Legal

// It depends, the return type is either the type of object pointed by beg or int, whichever reserves the highest accuracy. 
// since (*beg+0) is a arithmetic expression and returns rvalue, thus decltype(*beg+0) returns just a type, not a reference 
// to a type.

// the restriction is that the arguments passed should have dereference oprator defined, and that there should be a conversion
// between type of object pointed to by It and 0.
