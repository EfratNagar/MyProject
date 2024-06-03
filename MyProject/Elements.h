#pragma once
#include <list>
#include <string>
#include <vector>
//מבנה הרשימות
class Navigations {
   
public:
    int x;
    int y;
    Navigations(int x, int y) :x(x), y(y) {}
    int Getx() { return x; }
    int Gety() { return y; }

};
struct Bomb {
    double x;
    double y;
public:
    Bomb(double x, double y) :x(x), y(y){}
   
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
    std::vector<std::string> NameList;
public:
    Kidnapped(int x, int y, std::vector<std::string> NameList) :x(x), y(y), NameList(NameList){}
};
