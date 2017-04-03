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
    func(ret, args);
    
    ret.LuaPush(L);
    return 1;
}

}