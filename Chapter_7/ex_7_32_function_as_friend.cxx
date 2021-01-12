#include <iostream>
#include <string>
#include <vector>

class Screen;  //have to be declared before Window_mgr since Window_mgr has members of this type

class Window_mgr{
    private:
	//std::vector<Screen> screens{Screen(24, 80,' ')};  //Wrong, Screen is not defined yet, don't know its size
	std::vector<Screen> screens;    
    public:
	using ScreenIndex = std::vector<Screen>::size_type;
	void clear(ScreenIndex);

        Window_mgr();  //if we don't define our own constructor, synthesized default construtor will initialize object of Window_mgr to have a empty vector 'screens', so we need to take care of that.
};


class Screen{
    //since we are friend-declaring a member function of Window_mgr, we must define class Window_mgr before doing so.
    friend void Window_mgr::clear(ScreenIndex);
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

//default constructor, to initialize screens with one element, object of type Screen 
Window_mgr::Window_mgr():screens{Screen(24, 80, ' ')}{}

void Window_mgr::clear(ScreenIndex i ){
    Screen &r = screens[i];
    r.contents = std::string(r.height * r.width, ' ' );
    r.cursor = 0;
}

int main(){
    return 0;
}
