#ifndef AU_LUA_H
#define AU_LUA_H

#include <iostream>
#include <string>
#include <vector>
#include <map>

#include "auluafunc.h"

namespace Au{

int _luaProc(lua_State* L);

class Lua
{
public:
    Lua()
    : L(0) {}
    ~Lua()
    { if(L) lua_close(L); }
    void Init()
    {
        L = luaL_newstate();
        /*
        lua_createtable(L, 0, 0);
        lua_pushnumber(L, 10);
        lua_setfield(L, -2, "boopValue");
        lua_pushnumber(L, 3);
        lua_setfield(L, -2, "boopValue2");
        lua_setglobal(L, "Table");
        */
        
        //lua_pushstring(L, "Pepperoni");
        //lua_setglobal(L, "MyString");
    }
    void Cleanup()
    {
        
    }
    
    void DoFile(const std::string& filename)
    {
        luaL_dofile(L, filename.c_str());
        const char* err = lua_tostring(L, -1);
        if(err)
            std::cout << err << std::endl;
    }
    
    // Type shenanigans ==================
    
    template<typename T>
    LuaType& BindType()
    { return LuaType::Get<T>(); }
    
    //====================================
    /*
    void SetGlobal(const LuaValue& value, const std::string& name)
    {
        value.LuaPush(L);
        lua_setglobal(L, name.c_str());
    }
    
    template<typename T>
    T GetGlobal(const std::string& name)
    {
        LuaValue val = T();
        lua_getglobal(L, name.c_str());
        val.LuaPop(L);
        return val.Get<T>();
    }
    */
    LuaFunc& GetFunction(unsigned id)
    { return _funcs[id]; }
    template<typename Ret, typename... Args>
    void Bind(Ret (*fn)(Args... args), const std::string& name)
    {
        LuaFunc func = LuaFunc(fn);
        _luaBindFunc(_funcs.size(), name);
        _funcs.push_back(func);
    }
    
    template<typename Type, typename Class>
    void Bind(Type Class::* member, const std::string& name)
    {
        LuaType* t = LuaType::GetPtr<Class>();
        LuaType* tptr = LuaType::GetPtr<Class*>();
        t->Member(member, name);
        tptr->Member(member, name);
    }
    
    template<typename Class, typename Ret, typename... Args>
    void Bind(Ret (Class::*fn)(Args... args), const std::string& name)
    {
        LuaType* t = LuaType::GetPtr<Class>();
        LuaType* tptr = LuaType::GetPtr<Class*>();
        LuaFunc func = LuaFunc(fn);
        t->Function(LuaType::MemberFunc(name, this, _funcs.size(), &_luaProc));
        tptr->Function(LuaType::MemberFunc(name, this, _funcs.size(), &_luaProc));
        _funcs.push_back(func);
    }
    
private:
    void _luaBindFunc(unsigned funcIndex, const std::string& name)
    {
        lua_pushnumber(L, funcIndex);
        lua_pushlightuserdata(L, this);
        lua_pushcclosure(L, &_luaProc, 2);
        lua_setglobal(L, name.c_str());
    }
    lua_State* L;
    
    std::vector<LuaFunc> _funcs;
};

}

#endif
