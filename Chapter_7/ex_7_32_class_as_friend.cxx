#include <iostream>
#include <string>
#include <vector>

class Screen{
    public:
	friend class Window_mgr;  //friend declaration can appear before the actual declaration of class and (individual) functions. For member function of a class, we have to define the class before friend declares its member function
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

class Window_mgr{
    private:
        std::vector<Screen> screens{Screen(24, 80, ' ')};  //OK, Screen has already being defined
    public:
	//for type member, if you want to use it as a return type, then when you define the function, you need to use scope operator, ie. Window_mgr::ScreenIndex function_name(parameter list){......}
	using ScreenIndex = std::vector<Screen>::size_type;
	void clear(ScreenIndex);
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

inline 
void Window_mgr::clear(ScreenIndex i){
    screens[i].contents = std::string(screens[i].height * screens[i].width, ' ');
    screens[i].cursor = 0;
}

int main(){
    return 0;
}
