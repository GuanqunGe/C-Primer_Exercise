#include <string>

class Screen{
    public:
        using pos = std::string::size_type;

        //constructor
        Screen() =default;
        Screen(pos ih, pos iw): height(ih), width(iw),contents(ih*iw, ' '){}
        Screen(pos ih, pos iw, char ic):height(ih), width(iw), contents(ih*iw, ic){}


        char get() const {return contents[cursor];}
        char get(pos, pos) const;
	inline Screen &move(pos, pos);

    private:
        pos height = 0, width = 0;
        pos cursor = 0;
	std::string contents;
};

inline 
char Screen::get(pos ih, pos iw) const   //explicitly defined as inline
{
    return contents[ih*width + iw];
}

Screen &Screen::move(pos ih, pos iw){
    cursor = ih*width + iw;
    return *this;
}


int main(){
 
    return 0;
}
