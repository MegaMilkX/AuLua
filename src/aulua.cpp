#include "aulua.h"

namespace Au{
    
int _luaProc(lua_State* L)
{
    Lua* lua = (Lua*)lua_touserdata(L, lua_upvalueindex(2));
    LuaFunc func = lua->GetFunction((int)lua_tonumber(L, lua_upvalueindex(1)));

    if(!func.GrabArgs(L))
        return 0;
    
    return func.Call(L);
}

}