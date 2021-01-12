#include <iostream>
#include <string>

class Screen{
    public:
        using pos = std::string::size_type;

        //constructor
        Screen() =default;
        Screen(pos ih, pos iw): height(ih), width(iw),contents(ih*iw, ' '){}
        Screen(pos ih, pos iw, char ic):height(ih), width(iw), contents(ih*iw, ic){}

 	//member functions
        char get() const {return contents[cursor];}
        char get(pos, pos) const;
	inline Screen &move(pos, pos);

        //set a certain char
	Screen &set(char);
	Screen &set(pos, pos, char);

  	//display the string
  	Screen &display(std::ostream &io){ do_display(io); return *this;}
	const Screen &display(std::ostream &io) const{ do_display(io); return *this;}
    private:
        pos height = 0, width = 0;
        pos cursor = 0;
	std::string contents;
        void do_display(std::ostream &io) const { io << contents; }
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

inline
Screen &Screen::set(char ic)
{
    contents[cursor] = ic;
    return *this;
}

inline
Screen &Screen::set(pos ih, pos iw, char ic){
    contents[ih*width + iw] = ic;
    return *this;
}

int main(){

    Screen myScreen(5, 5, 'x'); 
    myScreen.move(4, 0).set('#').display(std::cout); 
    std::cout << "\n";
    myScreen.display(std::cout);
    std::cout << "\n";
    std::cout << std::endl;
    return 0;
}
