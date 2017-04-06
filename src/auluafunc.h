#ifndef AU_LUA_FUNC_H
#define AU_LUA_FUNC_H

#include "auluaval.h"

namespace Au{

template<typename FuncType, FuncType Func>
void _luaCallNR(LuaVal& ret, std::vector<LuaVal>& args)
{
    (*Func)();
}
template<typename FuncType, FuncType Func, 
    typename Arg0>
void _luaCallNR(LuaVal& ret, std::vector<LuaVal>& args)
{
    (*Func)(
        args[0].Get<Arg0>()
    );
}
template<typename FuncType, FuncType Func, 
    typename Arg0, 
    typename Arg1>
void _luaCallNR(LuaVal& ret, std::vector<LuaVal>& args)
{
    (*Func)(
        args[0].Get<Arg0>(),
        args[1].Get<Arg1>()
    );
}
template<typename FuncType, FuncType Func, 
    typename Arg0, 
    typename Arg1, 
    typename Arg2>
void _luaCallNR(LuaVal& ret, std::vector<LuaVal>& args)
{
    (*Func)(
        args[0].Get<Arg0>(),
        args[1].Get<Arg1>(),
        args[2].Get<Arg2>()
    );
}
template<typename FuncType, FuncType Func, 
    typename Arg0, 
    typename Arg1, 
    typename Arg2, 
    typename Arg3>
void _luaCallNR(LuaVal& ret, std::vector<LuaVal>& args)
{
    (*Func)(
        args[0].Get<Arg0>(),
        args[1].Get<Arg1>(),
        args[2].Get<Arg2>(),
        args[3].Get<Arg3>()
    );
}
template<typename FuncType, FuncType Func, 
    typename Arg0, 
    typename Arg1, 
    typename Arg2, 
    typename Arg3, 
    typename Arg4>
void _luaCallNR(LuaVal& ret, std::vector<LuaVal>& args)
{
    (*Func)(
        args[0].Get<Arg0>(),
        args[1].Get<Arg1>(),
        args[2].Get<Arg2>(),
        args[3].Get<Arg3>(),
        args[4].Get<Arg4>()
    );
}
template<typename FuncType, FuncType Func, 
    typename Arg0, 
    typename Arg1, 
    typename Arg2, 
    typename Arg3, 
    typename Arg4, 
    typename Arg5>
void _luaCallNR(LuaVal& ret, std::vector<LuaVal>& args)
{
    (*Func)(
        args[0].Get<Arg0>(),
        args[1].Get<Arg1>(),
        args[2].Get<Arg2>(),
        args[3].Get<Arg3>(),
        args[4].Get<Arg4>(),
        args[5].Get<Arg5>()
    );
}
template<typename FuncType, FuncType Func, 
    typename Arg0, 
    typename Arg1, 
    typename Arg2, 
    typename Arg3, 
    typename Arg4, 
    typename Arg5, 
    typename Arg6>
void _luaCallNR(LuaVal& ret, std::vector<LuaVal>& args)
{
    (*Func)(
        args[0].Get<Arg0>(),
        args[1].Get<Arg1>(),
        args[2].Get<Arg2>(),
        args[3].Get<Arg3>(),
        args[4].Get<Arg4>(),
        args[5].Get<Arg5>(),
        args[6].Get<Arg6>()
    );
}
template<typename FuncType, FuncType Func, 
    typename Arg0, 
    typename Arg1, 
    typename Arg2, 
    typename Arg3, 
    typename Arg4, 
    typename Arg5, 
    typename Arg6, 
    typename Arg7>
void _luaCallNR(LuaVal& ret, std::vector<LuaVal>& args)
{
    (*Func)(
        args[0].Get<Arg0>(),
        args[1].Get<Arg1>(),
        args[2].Get<Arg2>(),
        args[3].Get<Arg3>(),
        args[4].Get<Arg4>(),
        args[5].Get<Arg5>(),
        args[6].Get<Arg6>(),
        args[7].Get<Arg7>()
    );
}
template<typename FuncType, FuncType Func, 
    typename Arg0, 
    typename Arg1, 
    typename Arg2, 
    typename Arg3, 
    typename Arg4, 
    typename Arg5, 
    typename Arg6, 
    typename Arg7, 
    typename Arg8>
void _luaCallNR(LuaVal& ret, std::vector<LuaVal>& args)
{
    (*Func)(
        args[0].Get<Arg0>(),
        args[1].Get<Arg1>(),
        args[2].Get<Arg2>(),
        args[3].Get<Arg3>(),
        args[4].Get<Arg4>(),
        args[5].Get<Arg5>(),
        args[6].Get<Arg6>(),
        args[7].Get<Arg7>(),
        args[8].Get<Arg8>()
    );
}
template<typename FuncType, FuncType Func, 
    typename Arg0, 
    typename Arg1, 
    typename Arg2, 
    typename Arg3, 
    typename Arg4, 
    typename Arg5, 
    typename Arg6, 
    typename Arg7, 
    typename Arg8, 
    typename Arg9>
void _luaCallNR(LuaVal& ret, std::vector<LuaVal>& args)
{
    (*Func)(
        args[0].Get<Arg0>(),
        args[1].Get<Arg1>(),
        args[2].Get<Arg2>(),
        args[3].Get<Arg3>(),
        args[4].Get<Arg4>(),
        args[5].Get<Arg5>(),
        args[6].Get<Arg6>(),
        args[7].Get<Arg7>(),
        args[8].Get<Arg8>(),
        args[9].Get<Arg9>()
    );
}
template<typename FuncType, FuncType Func, 
    typename Arg0, 
    typename Arg1, 
    typename Arg2, 
    typename Arg3, 
    typename Arg4, 
    typename Arg5, 
    typename Arg6, 
    typename Arg7, 
    typename Arg8, 
    typename Arg9, 
    typename Arg10>
void _luaCallNR(LuaVal& ret, std::vector<LuaVal>& args)
{
    (*Func)(
        args[0].Get<Arg0>(),
        args[1].Get<Arg1>(),
        args[2].Get<Arg2>(),
        args[3].Get<Arg3>(),
        args[4].Get<Arg4>(),
        args[5].Get<Arg5>(),
        args[6].Get<Arg6>(),
        args[7].Get<Arg7>(),
        args[8].Get<Arg8>(),
        args[9].Get<Arg9>(),
        args[10].Get<Arg10>()
    );
}

template<typename FuncType, FuncType Func>
void _luaCallR(LuaVal& ret, std::vector<LuaVal>& args)
{
    ret = (*Func)();
}
template<typename FuncType, FuncType Func, 
    typename Arg0>
void _luaCallR(LuaVal& ret, std::vector<LuaVal>& args)
{
    ret = (*Func)(
        args[0].Get<Arg0>()
    );
}
template<typename FuncType, FuncType Func, 
    typename Arg0, 
    typename Arg1>
void _luaCallR(LuaVal& ret, std::vector<LuaVal>& args)
{
    ret = (*Func)(
        args[0].Get<Arg0>(),
        args[1].Get<Arg1>()
    );
}
template<typename FuncType, FuncType Func, 
    typename Arg0, 
    typename Arg1, 
    typename Arg2>
void _luaCallR(LuaVal& ret, std::vector<LuaVal>& args)
{
    ret = (*Func)(
        args[0].Get<Arg0>(),
        args[1].Get<Arg1>(),
        args[2].Get<Arg2>()
    );
}
template<typename FuncType, FuncType Func, 
    typename Arg0, 
    typename Arg1, 
    typename Arg2, 
    typename Arg3>
void _luaCallR(LuaVal& ret, std::vector<LuaVal>& args)
{
    ret = (*Func)(
        args[0].Get<Arg0>(),
        args[1].Get<Arg1>(),
        args[2].Get<Arg2>(),
        args[3].Get<Arg3>()
    );
}
template<typename FuncType, FuncType Func, 
    typename Arg0, 
    typename Arg1, 
    typename Arg2, 
    typename Arg3, 
    typename Arg4>
void _luaCallR(LuaVal& ret, std::vector<LuaVal>& args)
{
    ret = (*Func)(
        args[0].Get<Arg0>(),
        args[1].Get<Arg1>(),
        args[2].Get<Arg2>(),
        args[3].Get<Arg3>(),
        args[4].Get<Arg4>()
    );
}
template<typename FuncType, FuncType Func, 
    typename Arg0, 
    typename Arg1, 
    typename Arg2, 
    typename Arg3, 
    typename Arg4, 
    typename Arg5>
void _luaCallR(LuaVal& ret, std::vector<LuaVal>& args)
{
    ret = (*Func)(
        args[0].Get<Arg0>(),
        args[1].Get<Arg1>(),
        args[2].Get<Arg2>(),
        args[3].Get<Arg3>(),
        args[4].Get<Arg4>(),
        args[5].Get<Arg5>()
    );
}
template<typename FuncType, FuncType Func, 
    typename Arg0, 
    typename Arg1, 
    typename Arg2, 
    typename Arg3, 
    typename Arg4, 
    typename Arg5, 
    typename Arg6>
void _luaCallR(LuaVal& ret, std::vector<LuaVal>& args)
{
    ret = (*Func)(
        args[0].Get<Arg0>(),
        args[1].Get<Arg1>(),
        args[2].Get<Arg2>(),
        args[3].Get<Arg3>(),
        args[4].Get<Arg4>(),
        args[5].Get<Arg5>(),
        args[6].Get<Arg6>()
    );
}
template<typename FuncType, FuncType Func, 
    typename Arg0, 
    typename Arg1, 
    typename Arg2, 
    typename Arg3, 
    typename Arg4, 
    typename Arg5, 
    typename Arg6, 
    typename Arg7>
void _luaCallR(LuaVal& ret, std::vector<LuaVal>& args)
{
    ret = (*Func)(
        args[0].Get<Arg0>(),
        args[1].Get<Arg1>(),
        args[2].Get<Arg2>(),
        args[3].Get<Arg3>(),
        args[4].Get<Arg4>(),
        args[5].Get<Arg5>(),
        args[6].Get<Arg6>(),
        args[7].Get<Arg7>()
    );
}
template<typename FuncType, FuncType Func, 
    typename Arg0, 
    typename Arg1, 
    typename Arg2, 
    typename Arg3, 
    typename Arg4, 
    typename Arg5, 
    typename Arg6, 
    typename Arg7, 
    typename Arg8>
void _luaCallR(LuaVal& ret, std::vector<LuaVal>& args)
{
    ret = (*Func)(
        args[0].Get<Arg0>(),
        args[1].Get<Arg1>(),
        args[2].Get<Arg2>(),
        args[3].Get<Arg3>(),
        args[4].Get<Arg4>(),
        args[5].Get<Arg5>(),
        args[6].Get<Arg6>(),
        args[7].Get<Arg7>(),
        args[8].Get<Arg8>()
    );
}
template<typename FuncType, FuncType Func, 
    typename Arg0, 
    typename Arg1, 
    typename Arg2, 
    typename Arg3, 
    typename Arg4, 
    typename Arg5, 
    typename Arg6, 
    typename Arg7, 
    typename Arg8, 
    typename Arg9>
void _luaCallR(LuaVal& ret, std::vector<LuaVal>& args)
{
    ret = (*Func)(
        args[0].Get<Arg0>(),
        args[1].Get<Arg1>(),
        args[2].Get<Arg2>(),
        args[3].Get<Arg3>(),
        args[4].Get<Arg4>(),
        args[5].Get<Arg5>(),
        args[6].Get<Arg6>(),
        args[7].Get<Arg7>(),
        args[8].Get<Arg8>(),
        args[9].Get<Arg9>()
    );
}
template<typename FuncType, FuncType Func, 
    typename Arg0, 
    typename Arg1, 
    typename Arg2, 
    typename Arg3, 
    typename Arg4, 
    typename Arg5, 
    typename Arg6, 
    typename Arg7, 
    typename Arg8, 
    typename Arg9, 
    typename Arg10>
void _luaCallR(LuaVal& ret, std::vector<LuaVal>& args)
{
    ret = (*Func)(
        args[0].Get<Arg0>(),
        args[1].Get<Arg1>(),
        args[2].Get<Arg2>(),
        args[3].Get<Arg3>(),
        args[4].Get<Arg4>(),
        args[5].Get<Arg5>(),
        args[6].Get<Arg6>(),
        args[7].Get<Arg7>(),
        args[8].Get<Arg8>(),
        args[9].Get<Arg9>(),
        args[10].Get<Arg10>()
    );
}

template<typename T> using identity_t = T; // VS2013 hack
template<typename... Args>
std::vector<LuaVal> _createArgListFn()
{
    std::vector<LuaVal> v = {LuaVal(identity_t<Args>())...};
    v.erase(v.begin());
    return v;
}

class LuaFunc
{
public:
    void operator()(LuaVal& ret, std::vector<LuaVal>& args)
    {
        (*_callFn)(ret, args);
    }

    int ArgCount() { return _argCount; }
    std::vector<LuaVal> Args() { return _createArgList(); }
    
    template<typename... Args>
    LuaFunc(void (*fn)(Args... args))
    {
        _callFn = &_luaCallNR<void (*)(Args...), fn, Args...>;
        _argCount = sizeof...(Args);
        _createArgList = &_createArgListFn<int, Args...>;
    }
    template<typename Ret, typename... Args>
    LuaFunc(Ret (*fn)(Args... args))
    {
        _callFn = &_luaCallR<Ret (*)(Args...), fn, Args...>;
        _argCount = sizeof...(Args);
        _createArgList = &_createArgListFn<int, Args...>;
    }
private:
    std::vector<LuaVal> (*_createArgList)();

    void (*_callFn)(LuaVal&, std::vector<LuaVal>&);
    int _argCount;
};

}

#endif
