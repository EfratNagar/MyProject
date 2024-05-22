#pragma once
#include <list>
#include <string>
class Navigations {
   
public:
    int x;
    int y;
    Navigations(int x, int y) :x(x), y(y) {}
    int Getx() { return x; }
    int Gety() { return y; }

};
struct Bomb {
    int x;
    int y;
    int misPicture;
public:
    Bomb(int x, int y, int misPicture) :x(x), y(y), misPicture(misPicture){}
   
};
struct Terrorist {
    int x;
    int y;
    int count;
public:
    Terrorist(int x, int y,int count) :x(x), y(y), count(count){}    
};
struct Kidnapped {
    int x;
    int y;
    std::list<std::string> NameList;
public:
    Kidnapped(int x, int y, std::list<std::string> NameList) :x(x), y(y), NameList(NameList){}
};
