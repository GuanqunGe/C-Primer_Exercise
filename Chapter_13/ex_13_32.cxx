Pointer like HasPtr does not benefit from defining a wap function, because using the std::swap() function
on pointer-like HasPtr also does not involve dynamically allocate new string object. std::swap() use copy
initialization and copy assignment, both of which just involves moving around pointers.
