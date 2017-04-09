#ifndef AU_LUA_TYPE_H
#define AU_LUA_TYPE_H

#include <vector>
#include <string>
#include <map>
#include <iostream>
#include <typeinfo>

extern "C" {
#include "ext/lua-5.1.5/src/lua.h"
#include "ext/lua-5.1.5/src/lualib.h"
#include "ext/lua-5.1.5/src/lauxlib.h"
}

namespace Au{
    
template<typename T> struct bare_type { typedef T type; };
template<typename T> struct bare_type<const T> : bare_type<T> {};
template<typename T> struct bare_type<T&> : bare_type<T> {};
template<typename T> struct bare_type<T&&> : bare_type<T> {};
    
template<typename T>
static int LuaTypeIndex()
{
    static int i = NextLuaTypeIndex();
    return i;
}
static int NextLuaTypeIndex()
{
    static int id;
    return ++id;
}

template<typename T> 
inline void _pushFn(lua_State* L, void* data) { lua_pushnil(L); }
template<> 
inline void _pushFn<char>(lua_State* L, void* data) { lua_pushnumber(L, (lua_Number)*(char*)data); }
template<> 
inline void _pushFn<unsigned char>(lua_State* L, void* data) { lua_pushnumber(L, (lua_Number)*(unsigned char*)data); }
template<> 
inline void _pushFn<short>(lua_State* L, void* data) { lua_pushnumber(L, (lua_Number)*(short*)data); }
template<> 
inline void _pushFn<unsigned short>(lua_State* L, void* data) { lua_pushnumber(L, (lua_Number)*(unsigned short*)data); }
template<> 
inline void _pushFn<int>(lua_State* L, void* data) { lua_pushnumber(L, (lua_Number)*(int*)data); }
template<> 
inline void _pushFn<unsigned int>(lua_State* L, void* data) { lua_pushnumber(L, (lua_Number)*(unsigned int*)data); }
template<> 
inline void _pushFn<long>(lua_State* L, void* data) { lua_pushnumber(L, (lua_Number)*(long*)data); }
template<> 
inline void _pushFn<unsigned long>(lua_State* L, void* data) { lua_pushnumber(L, (lua_Number)*(unsigned long*)data); }
template<> 
inline void _pushFn<long long>(lua_State* L, void* data) { lua_pushnumber(L, (lua_Number)*(long long*)data); }
template<> 
inline void _pushFn<unsigned long long>(lua_State* L, void* data) { lua_pushnumber(L, (lua_Number)*(unsigned long long*)data); }
template<> 
inline void _pushFn<float>(lua_State* L, void* data) { lua_pushnumber(L, *(float*)data); }
template<> 
inline void _pushFn<double>(lua_State* L, void* data) { lua_pushnumber(L, *(double*)data); }
template<> 
inline void _pushFn<char*>(lua_State* L, void* data) { lua_pushstring(L, *(char**)data); }
template<> 
inline void _pushFn<std::string>(lua_State* L, void* data) { lua_pushstring(L, (*(std::string*)data).c_str()); }
template<> 
inline void _pushFn<bool>(lua_State* L, void* data) { lua_pushboolean(L, (int)*(bool*)data); }

template<typename T>
inline void _popFn(lua_State* L, void* data) { lua_pop(L, 1); }
template<>
inline void _popFn<char>(lua_State* L, void* data) { (*(char*)data) = (char)lua_tonumber(L, -1); lua_pop(L, 1); }
template<>
inline void _popFn<unsigned char>(lua_State* L, void* data) { (*(unsigned char*)data) = (unsigned char)lua_tonumber(L, -1); lua_pop(L, 1); }
template<>
inline void _popFn<short>(lua_State* L, void* data) { (*(short*)data) = (short)lua_tonumber(L, -1); lua_pop(L, 1); }
template<>
inline void _popFn<unsigned short>(lua_State* L, void* data) { (*(unsigned short*)data) = (unsigned short)lua_tonumber(L, -1); lua_pop(L, 1); }
template<>
inline void _popFn<int>(lua_State* L, void* data) { (*(int*)data) = (int)lua_tonumber(L, -1); lua_pop(L, 1); }
template<>
inline void _popFn<unsigned int>(lua_State* L, void* data) { (*(unsigned int*)data) = (unsigned int)lua_tonumber(L, -1); lua_pop(L, 1); }
template<>
inline void _popFn<long>(lua_State* L, void* data) { (*(long*)data) = (long)lua_tonumber(L, -1); lua_pop(L, 1); }
template<>
inline void _popFn<unsigned long>(lua_State* L, void* data) { (*(unsigned long*)data) = (unsigned long)lua_tonumber(L, -1); lua_pop(L, 1); }
template<>
inline void _popFn<long long>(lua_State* L, void* data) { (*(long long*)data) = (long long)lua_tonumber(L, -1); lua_pop(L, 1); }
template<>
inline void _popFn<unsigned long long>(lua_State* L, void* data) { (*(unsigned long long*)data) = (unsigned long long)lua_tonumber(L, -1); lua_pop(L, 1); }
template<>
inline void _popFn<float>(lua_State* L, void* data) { (*(float*)data) = (float)lua_tonumber(L, -1); lua_pop(L, 1); }
template<>
inline void _popFn<double>(lua_State* L, void* data) { (*(double*)data) = (double)lua_tonumber(L, -1); lua_pop(L, 1); }
template<>
inline void _popFn<char*>(lua_State* L, void* data) { (*(char**)data) = (char*)lua_tostring(L, -1); lua_pop(L, 1); }
template<>
inline void _popFn<std::string>(lua_State* L, void* data) { (*(std::string*)data) = std::string(lua_tostring(L, -1), lua_strlen(L, -1)); lua_pop(L, 1); }
template<>
inline void _popFn<bool>(lua_State* L, void* data) { (*(bool*)data) = lua_toboolean(L, -1) != 0; lua_pop(L, 1); }

struct LuaType
{    
    struct MemberField
    {
        MemberField()
        : type(0), offset(0) {}
        MemberField(LuaType* type, char* offset, const std::string& name)
        : type(type), offset(offset), name(name) {}
        LuaType* type;
        char* offset;
        std::string name;
    };
    
    struct MemberFunc
    {
        MemberFunc()
        : statePtr(0), fnIndex(0) {}
        MemberFunc(const std::string& name, void* statePtr, int fnIndex, int (*cfn)(lua_State*))
        : name(name), statePtr(statePtr), fnIndex(fnIndex), cfn(cfn) {}
        std::string name;
        void* statePtr;
        int fnIndex;
        int (*cfn)(lua_State*);
    };

    LuaType()
    : _typeIndex(0),
      _push(0),
      _pop(0)
    {}
    template<typename T>
    LuaType(T* dummy)
    : _typeIndex(LuaTypeIndex<T>()),
      _push(&_pushFn<T>),
      _pop(&_popFn<T>)
    {}
    
    int _typeIndex;
    std::vector<MemberField> members;
    std::vector<MemberFunc> functions;
    
    template<typename T>
    static LuaType& Get()
    {
        static LuaType type = LuaType((T*)0);
        return type;
    }
    
    template<typename T>
    static LuaType* GetPtr()
    { return &(Get<T>()); }
    
    template<typename Type, typename Class>
    LuaType& Member(Type Class::* member, const std::string& name)
    {
        if(LuaTypeIndex<Class>() != _typeIndex)
            return *this;
        MemberField m;
        m.type = LuaType::GetPtr<Type>();
        Class* c = 0;
        m.offset = (char*)((char*)&(c->*member) - (char*)c);
        m.name = name;
        members.push_back(m);
        return *this;
    }
    
    void Function(const MemberFunc& func)
    {
        functions.push_back(func);
    }
    
    template<typename Class, typename Ret, typename... Args>
    LuaType& Function(Ret (Class::*fn)(Args... args), const std::string& name)
    {
        return *this;
    }
    
    void LuaPush(lua_State* L, void* data) const
    {
        if(!_push)
        {
            lua_pushnil(L);
            return;
        }
        
        if(members.empty())
        {
            _push(L, data);
        }
        else
        {
            lua_createtable(L, 0, 0);
            lua_pushlightuserdata(L, data);
            lua_setfield(L, -2, "this");
            
            for(unsigned i = 0; i < members.size(); ++i)
            {
                members[i].type->LuaPush(L, (void*)((char*)data + (int)members[i].offset));
                lua_setfield(L, -2, members[i].name.c_str());
            }
            
            for(unsigned i = 0; i < functions.size(); ++i)
            {
                lua_pushnumber(L, functions[i].fnIndex);
                lua_pushlightuserdata(L, functions[i].statePtr);
                lua_pushcclosure(L, functions[i].cfn, 2);
                lua_setfield(L, -2, functions[i].name.c_str());
            }
        }
    }
    
    void LuaPop(lua_State* L, void* data)
    {
        if(!_pop)
            return;
        
        if(members.empty())
        {
            _pop(L, data);
        }
        else
        {
            for(unsigned i = 0; i < members.size(); ++i)
            {
                lua_pushstring(L, members[i].name.c_str());
                lua_gettable(L, -2);
                members[i].type->LuaPop(L, (void*)((char*)data + (int)members[i].offset));
            }
        }
    }
private:
    void (*_push)(lua_State*, void*);
    void (*_pop)(lua_State*, void*);
};

}

#endif
