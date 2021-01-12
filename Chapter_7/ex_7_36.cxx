struct X{
    X(int i, int j): base(i), rem(base%j) {}  // X (int i, int j):base(i), rem(i%j){}
    int rem, base;
};

// rem will be initialized first, but at that point, base hasn't been initialized yet
