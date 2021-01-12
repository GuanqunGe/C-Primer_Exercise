1 typedef string Type;
2 Type initVal();
3 class Exercise{
4    public:
5	typedef double Type;
6	Type setVal(Type);
7	Type initVal();
8    private:
9	int val;
10 };

11 Type Exercise::setVal(Type parm){
12    val = parm + initVal();
13    return val;
14 }

/**********************************************************
 * line 1. Type is an alias for string
 * line 2. Type, again is an alias for string, function initVal() is declared
 * line 5. Type hides the former typedef of Type in the outer scope, now Type is an alias for double
 * line 6. during compilation, compiler will first look for Type in class before declaration of setVal, so Type on the return type and the parameter type means double. 
 * line 7. same reason as line 6. Type here is double. initVal() is defined as another function, in the scope inside class.
 * line 11. return Type is string because it's outside of the class and the compiler hasn't seen the class name yet when compiler sees it. setVal() is a member function of Exercise as denoted by the scope operator 'Exercise::', the second Type is double because the compiler now has seen the class name, and it successfully found a typedef for Type inside the class definition. 
 * line 12. val is the class member, parm is the function parameter, initVal is the class member function, again because we are in scope of class, and there is a declaration of initVal inside the class. 
 * line 13. return by the value of class member val.
 *
 * Error: The return type in the definition of setVal() doesn't match its declaration, and the return type in the function body, should change line 11 to:   Exercise::Type Exercise::setVal(Type parm)
