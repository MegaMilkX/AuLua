#include "aulua.h"

namespace Au{
    
int _luaProc(lua_State* L)
{
    Lua* lua = (Lua*)lua_touserdata(L, lua_upvalueindex(2));
    LuaFunc func = lua->GetFunction((int)lua_tonumber(L, lua_upvalueindex(1)));
    
    int luaArgCount = lua_gettop(L);
    LuaVal ret;
    std::vector<LuaVal> args = func.Args();
    int argCount = luaArgCount < args.size() ? luaArgCount - 1 : args.size() - 1;
    
    for(int i = argCount; i >= 0; --i)
    {
        args[i].LuaPop(L);    
    }
    
    if(func.IsMember())
    {
        lua_pushstring(L, "this");
        lua_gettable(L, -2);
        void* this_ = lua_touserdata(L, -1);
        lua_pop(L, 1);

        func(this_, ret, args);
    }
    else
    {
        func(ret, args);
    }
    
    ret.LuaPush(L);
    return 1;
}

}