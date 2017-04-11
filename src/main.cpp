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
    void SetMsg(const std::string& str)
    {
        msg = str;
    }
    
    int boob = 420;
    int poop;
    std::string msg = "ASDASD";
    
    char a[400];
};

Object object;
Object* GetObject()
{
    return &object;
}

void PrintObject(Object* o)
{
    std::cout << "[Object]: " << o << std::endl;
    std::cout << "boob: " << o->boob;
    std::cout << "poop: " << o->poop;
    std::cout << "msg: " << o->msg;
}

void Print(const std::string& msg)
{
    std::cout << ">: " << msg << std::endl;
}

void Print(int i)
{
    std::cout << ">: " << i << std::endl;
}

void Nothing()
{
    std::cout << "Nothing" << std::endl;
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
    lua.Bind(&Object::SetMsg, "SetMsg");
    
    lua.Bind(&Nothing, "Nothing");
    
    lua.Bind(&GetObject, "GetObject");
    lua.Bind(&PrintObject, "PrintObject");
    lua.Bind<void, const std::string&>(&Print, "Print");
    lua.Bind<void, int>(&Print, "Printi");

    lua.DoFile("script.lua");
    
    lua.Cleanup();
    std::getchar();
   
    return 0;
}
