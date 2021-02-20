if we defined sorted as: 
  Foo Foo::sorted() const &{
	return Foo(*this).sorted();
  }

It will run fine.
B/c Foo(*this) is part of the return expression, so object generated from Foo(*this) will be temporary.
Foo(*this).sorted() will actually call the sorted() && function.
