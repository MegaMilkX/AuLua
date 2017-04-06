#include <iostream>
#include <string>
#include <vector>

#include "aulua.h"

int Foo()
{
    std::cout << "Foo" << std::endl;
    return 0;
}

int Foo2(int i)
{
    std::cout << "Foo2: " << i << std::endl;
    return 0;
}

void Foo3(std::string c, float x, double y, int z)
{
    std::cout << c << ": " << x << " " << y << " " << z <<std::endl;
}

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

Object GetObject(int i)
{
    return Object();
}

void PrintObject(Object o)
{
    std::cout << "Object::boob: " << o.boob << std::endl;
    std::cout << "Object::poop: " << o.poop << std::endl;
    std::cout << "Object::msg: " << o.msg << std::endl;
}

void Print(std::string msg)
{
    std::cout << msg << std::endl;
}
   
int main()
{    
    Au::Lua lua;
    lua.Init();
    
    lua.BindType<Object>()
        .Member(&Object::boob, "boob")
        .Member(&Object::poop, "poop")
        .Member(&Object::msg, "msg")
        .Function(&Object::Beep, "Beep")
        .Function(&Object::Bop, "Bop");
    lua.SetGlobal(Object(), "Object");
    
    lua.BindFunction(&Foo2, "Foo2");
    lua.BindFunction(&Foo, "Foo");
    lua.BindFunction(&Foo3, "Foo3");
    lua.BindFunction(&Print, "Print");
    lua.BindFunction(&GetObject, "GetObject");
    lua.BindFunction(&PrintObject, "PrintObject");
    
    lua.DoFile("script.lua");
    
    lua.Cleanup();
    std::getchar();
   
    return 0;
}
