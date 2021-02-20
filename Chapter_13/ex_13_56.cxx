If we define:
Foo Foo::sorted() const &{
    Foo ret(*this);
    return ret.sorted();
}

sorted() function can only run on lvalue object.
*this will return lvalue reference to a const, thus ret is copy constructed.
ret.sorted() will call this specfic function, which will call itself recursively.

So if we defined sorted like this, then this function will run recursively and never end. 
