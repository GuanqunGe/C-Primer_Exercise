#ifndef SCREEN_H
#define SCREEN_H

#include <vector>
#include <iostream>
#include <utility>

template <typename T, typename U> class Screen;
template <typename T, typename U>
std::istream &operator>>(std::istream &, Screen<T, U> &);

template <typename T, typename U>
std::ostream &operator<<(std::ostream &, const Screen<T,U>&);

template <typename T, typename U>
class Screen{
    friend std::istream &operator>> <T, U>(std::istream &, Screen<T, U> &);
    friend std::ostream &operator<< <T, U>(std::ostream &, const Screen<T,U>&);
public:
    Screen() = default;
    Screen(const T &h, const T &w, const U &c): height(h), width(w), contents(height*width, c){}

    U get() const { return contents.at(cursor); }
    U get(T h, T w) const {return contents.at(h*width + w); }
    Screen &move(T r, T c);
private:
    T height = 0;
    T width = 0;
    T cursor = 0;
    std::vector<U> contents;
};

template <typename T, typename U>
inline Screen<T,U> &Screen<T, U>::move(T r, T c){
    cursor = r*width + c;
    return *this;
}

template <typename T, typename U>
std::istream &operator>>(std::istream &is, Screen<T, U> &screen){
    is >> screen.height >> screen.width >> screen.cursor;
    U element;
    is >> element;
    screen.contents = std::move(std::vector<U>(screen.height*screen.width, element));
    return is;
}

template <typename T, typename U>
std::ostream &operator<<(std::ostream &os, const Screen<T, U> &screen){
    for(T idx = 0; idx != screen.contents.size(); ++idx){
	os << screen.contents.at(idx) << " ";
	if( (idx+1) % screen.width ==0) os << "\n";
    }
    return os;
}
#endif
