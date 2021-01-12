class NoDefault{
    int imember;
    public:
    	NoDefault(int i): imember(i){}
};

class C{
    NoDefault c;
    public:
	C(int in = 0): c(in){}
};

int main(){
    return 0;
}
