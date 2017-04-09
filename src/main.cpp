#include <iostream>
#include <string>
#include <vector>

#include "aulua.h"

class Object
{
public:
    void Beep() 
    { std::cout << "Beepin'" << std::endl; }
    void Bop() 
    { std::cout << "Boppin'" << std::endl; }
    
    int boob = 420;
    int poop;
    std::string msg;
};

Object GetObject()
{
    return Object();
}

void Print(const std::string& msg)
{
    std::cout << ">: " << msg << std::endl;
}

void Print(int i)
{
    std::cout << ">: " << i << std::endl;
}
   
int main()
{    
    Au::Lua lua;
    lua.Init();
    
    lua.Bind(&Object::boob, "boob");
    lua.Bind(&Object::poop, "poop");
    lua.Bind(&Object::msg, "msg");
    lua.Bind(&Object::Beep, "Beep");
    lua.Bind(&Object::Bop, "Bop");
    
    lua.Bind(&GetObject, "GetObject");
    lua.Bind<void, const std::string&>(&Print, "Print");
    
    lua.DoFile("script.lua");
    
    lua.Cleanup();
    std::getchar();
   
    return 0;
}
