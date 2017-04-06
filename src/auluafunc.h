#ifndef AU_LUA_FUNC_H
#define AU_LUA_FUNC_H

#include "auluaval.h"

namespace Au{
/*
template<typename... Args>
void _luaCallNR(void (*fn)(void), LuaVal& ret, std::vector<LuaVal>& args)
{ ((void(*)(Args...))fn)(helper.Get<Args>()...); }*/
inline void _luaCallNR(void (*fn)(void), LuaVal& ret, std::vector<LuaVal>& args)
{
    ((void(*)())fn)(); 
}
template<typename Arg0>
void _luaCallNR(void (*fn)(void), LuaVal& ret, std::vector<LuaVal>& args)
{
    ((void(*)(Arg0))fn)(
        args[0].Get<Arg0>()
    ); 
}
template<typename Arg0, 
    typename Arg1>
void _luaCallNR(void (*fn)(void), LuaVal& ret, std::vector<LuaVal>& args)
{
    ((void(*)(Arg0, Arg1))fn)(
        args[0].Get<Arg0>(), 
        args[1].Get<Arg1>()
    ); 
}
template<typename Arg0, 
    typename Arg1, 
    typename Arg2>
void _luaCallNR(void (*fn)(void), LuaVal& ret, std::vector<LuaVal>& args)
{
    ((void(*)(Arg0, Arg1, Arg2))fn)(
        args[0].Get<Arg0>(), 
        args[1].Get<Arg1>(), 
        args[2].Get<Arg2>()
    ); 
}
template<typename Arg0, 
    typename Arg1, 
    typename Arg2, 
    typename Arg3>
void _luaCallNR(void (*fn)(void), LuaVal& ret, std::vector<LuaVal>& args)
{ 
    ((void(*)(Arg0, Arg1, Arg2, Arg3))fn)(
        args[0].Get<Arg0>(), 
        args[1].Get<Arg1>(), 
        args[2].Get<Arg2>(),
        args[3].Get<Arg3>()
    ); 
}
template<typename Arg0, 
    typename Arg1, 
    typename Arg2, 
    typename Arg3, 
    typename Arg4>
void _luaCallNR(void (*fn)(void), LuaVal& ret, std::vector<LuaVal>& args)
{ 
    ((void(*)(Arg0, Arg1, Arg2, Arg3, Arg4))fn)(
        args[0].Get<Arg0>(), 
        args[1].Get<Arg1>(), 
        args[2].Get<Arg2>(),
        args[3].Get<Arg3>(),
        args[4].Get<Arg4>()
    ); 
}
template<typename Arg0, 
    typename Arg1, 
    typename Arg2, 
    typename Arg3, 
    typename Arg4, 
    typename Arg5>
void _luaCallNR(void (*fn)(void), LuaVal& ret, std::vector<LuaVal>& args)
{ 
    ((void(*)(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5))fn)(
        args[0].Get<Arg0>(), 
        args[1].Get<Arg1>(), 
        args[2].Get<Arg2>(),
        args[3].Get<Arg3>(),
        args[4].Get<Arg4>(),
        args[5].Get<Arg5>()
    ); 
}
template<typename Arg0, 
    typename Arg1, 
    typename Arg2, 
    typename Arg3, 
    typename Arg4, 
    typename Arg5, 
    typename Arg6>
void _luaCallNR(void (*fn)(void), LuaVal& ret, std::vector<LuaVal>& args)
{ 
    ((void(*)(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6))fn)(
        args[0].Get<Arg0>(), 
        args[1].Get<Arg1>(), 
        args[2].Get<Arg2>(),
        args[3].Get<Arg3>(),
        args[4].Get<Arg4>(),
        args[5].Get<Arg5>(),
        args[6].Get<Arg6>()
    ); 
}
template<typename Arg0, 
    typename Arg1, 
    typename Arg2, 
    typename Arg3, 
    typename Arg4, 
    typename Arg5, 
    typename Arg6, 
    typename Arg7>
void _luaCallNR(void (*fn)(void), LuaVal& ret, std::vector<LuaVal>& args)
{ 
    ((void(*)(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7))fn)(
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
template<typename Arg0, 
    typename Arg1, 
    typename Arg2, 
    typename Arg3, 
    typename Arg4, 
    typename Arg5, 
    typename Arg6, 
    typename Arg7, 
    typename Arg8>
void _luaCallNR(void (*fn)(void), LuaVal& ret, std::vector<LuaVal>& args)
{ 
    ((void(*)(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8))fn)(
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
template<typename Arg0, 
    typename Arg1, 
    typename Arg2, 
    typename Arg3, 
    typename Arg4, 
    typename Arg5, 
    typename Arg6, 
    typename Arg7, 
    typename Arg8, 
    typename Arg9>
void _luaCallNR(void (*fn)(void), LuaVal& ret, std::vector<LuaVal>& args)
{ 
    ((void(*)(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Arg9))fn)(
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
template<typename Arg0, 
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
void _luaCallNR(void (*fn)(void), LuaVal& ret, std::vector<LuaVal>& args)
{ 
    ((void(*)(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Arg9, Arg10))fn)(
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
/*
template<typename Ret, typename... Args>
void _luaCallR(void (*fn)(void), LuaVal& ret, std::vector<LuaVal>& args)
{
    ArgHelper helper(args);
    ret = ((Ret(*)(Args...))fn)(helper.Get<Args>()...);
}
*/
template<typename Ret>
void _luaCallR(void (*fn)(void), LuaVal& ret, std::vector<LuaVal>& args)
{
    ret = ((Ret(*)())fn)(); 
}
template<typename Ret, typename Arg0>
void _luaCallR(void (*fn)(void), LuaVal& ret, std::vector<LuaVal>& args)
{
    ret = ((Ret(*)(Arg0))fn)(
        args[0].Get<Arg0>()
    );
}
template<typename Ret, typename Arg0, 
    typename Arg1>
void _luaCallR(void (*fn)(void), LuaVal& ret, std::vector<LuaVal>& args)
{
    ret = ((Ret(*)(Arg0, Arg1))fn)(
        args[0].Get<Arg0>(),
        args[1].Get<Arg1>()
    );
}
template<typename Ret, typename Arg0, 
    typename Arg1, 
    typename Arg2>
void _luaCallR(void (*fn)(void), LuaVal& ret, std::vector<LuaVal>& args)
{
    ret = ((Ret(*)(Arg0, Arg1, Arg2))fn)(
        args[0].Get<Arg0>(),
        args[1].Get<Arg1>(),
        args[2].Get<Arg2>()
    );
}
template<typename Ret, typename Arg0, 
    typename Arg1, 
    typename Arg2, 
    typename Arg3>
void _luaCallR(void (*fn)(void), LuaVal& ret, std::vector<LuaVal>& args)
{
    ret = ((Ret(*)(Arg0, Arg1, Arg2, Arg3))fn)(
        args[0].Get<Arg0>(),
        args[1].Get<Arg1>(),
        args[2].Get<Arg2>(),
        args[3].Get<Arg3>()
    );
}
template<typename Ret, typename Arg0, 
    typename Arg1, 
    typename Arg2, 
    typename Arg3, 
    typename Arg4>
void _luaCallR(void (*fn)(void), LuaVal& ret, std::vector<LuaVal>& args)
{
    ret = ((Ret(*)(Arg0, Arg1, Arg2, Arg3, Arg4))fn)(
        args[0].Get<Arg0>(),
        args[1].Get<Arg1>(),
        args[2].Get<Arg2>(),
        args[3].Get<Arg3>(),
        args[4].Get<Arg4>()
    );
}
template<typename Ret, typename Arg0, 
    typename Arg1, 
    typename Arg2, 
    typename Arg3, 
    typename Arg4, 
    typename Arg5>
void _luaCallR(void (*fn)(void), LuaVal& ret, std::vector<LuaVal>& args)
{
    ret = ((Ret(*)(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5))fn)(
        args[0].Get<Arg0>(),
        args[1].Get<Arg1>(),
        args[2].Get<Arg2>(),
        args[3].Get<Arg3>(),
        args[4].Get<Arg4>(),
        args[5].Get<Arg5>()
    );
}
template<typename Ret, typename Arg0, 
    typename Arg1, 
    typename Arg2, 
    typename Arg3, 
    typename Arg4, 
    typename Arg5, 
    typename Arg6>
void _luaCallR(void (*fn)(void), LuaVal& ret, std::vector<LuaVal>& args)
{
    ret = ((Ret(*)(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6))fn)(
        args[0].Get<Arg0>(),
        args[1].Get<Arg1>(),
        args[2].Get<Arg2>(),
        args[3].Get<Arg3>(),
        args[4].Get<Arg4>(),
        args[5].Get<Arg5>(),
        args[6].Get<Arg6>()
    );
}
template<typename Ret, typename Arg0, 
    typename Arg1, 
    typename Arg2, 
    typename Arg3, 
    typename Arg4, 
    typename Arg5, 
    typename Arg6, 
    typename Arg7>
void _luaCallR(void (*fn)(void), LuaVal& ret, std::vector<LuaVal>& args)
{
    ret = ((Ret(*)(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7))fn)(
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
template<typename Ret, typename Arg0, 
    typename Arg1, 
    typename Arg2, 
    typename Arg3, 
    typename Arg4, 
    typename Arg5, 
    typename Arg6, 
    typename Arg7, 
    typename Arg8>
void _luaCallR(void (*fn)(void), LuaVal& ret, std::vector<LuaVal>& args)
{
    ret = ((Ret(*)(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8))fn)(
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
template<typename Ret, typename Arg0, 
    typename Arg1, 
    typename Arg2, 
    typename Arg3, 
    typename Arg4, 
    typename Arg5, 
    typename Arg6, 
    typename Arg7, 
    typename Arg8, 
    typename Arg9>
void _luaCallR(void (*fn)(void), LuaVal& ret, std::vector<LuaVal>& args)
{
    ret = ((Ret(*)(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Arg9))fn)(
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
template<typename Ret, typename Arg0, 
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
void _luaCallR(void (*fn)(void), LuaVal& ret, std::vector<LuaVal>& args)
{
    ret = ((Ret(*)(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Arg9, Arg10))fn)(
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
/*
inline std::vector<LuaVal> _createArgListFn()
{ return std::vector<LuaVal>(); }
template<typename Arg0>
std::vector<LuaVal> _createArgListFn()
{ return { LuaVal(Arg0()) } }
template<typename Arg0, 
    typename Arg1>
std::vector<LuaVal> _createArgListFn()
{
    return { 
        LuaVal(Arg0()), 
        LuaVal(Arg1()) 
    } 
}
template<typename Arg0,
    typename Arg1,
    typename Arg2>
std::vector<LuaVal> _createArgListFn()
{
    return { 
        LuaVal(Arg0()), 
        LuaVal(Arg1()), 
        LuaVal(Arg2()) 
    } 
}
template<typename Arg0,
    typename Arg1,
    typename Arg2,
    typename Arg3>
std::vector<LuaVal> _createArgListFn()
{
    return { 
        LuaVal(Arg0()), 
        LuaVal(Arg1()), 
        LuaVal(Arg2()), 
        LuaVal(Arg3()) 
    } 
}
template<typename Arg0,
    typename Arg1,
    typename Arg2,
    typename Arg3,
    typename Arg4>
std::vector<LuaVal> _createArgListFn()
{
    return { 
        LuaVal(Arg0()), 
        LuaVal(Arg1()), 
        LuaVal(Arg2()), 
        LuaVal(Arg3()), 
        LuaVal(Arg4()) 
    } 
}
template<typename Arg0,
    typename Arg1,
    typename Arg2,
    typename Arg3,
    typename Arg4,
    typename Arg5>
std::vector<LuaVal> _createArgListFn()
{
    return { 
        LuaVal(Arg0()), 
        LuaVal(Arg1()), 
        LuaVal(Arg2()), 
        LuaVal(Arg3()), 
        LuaVal(Arg4()), 
        LuaVal(Arg5()) 
    } 
}
template<typename Arg0,
    typename Arg1,
    typename Arg2,
    typename Arg3,
    typename Arg4,
    typename Arg5,
    typename Arg6>
std::vector<LuaVal> _createArgListFn()
{
    return { 
        LuaVal(Arg0()), 
        LuaVal(Arg1()), 
        LuaVal(Arg2()), 
        LuaVal(Arg3()), 
        LuaVal(Arg4()), 
        LuaVal(Arg5()), 
        LuaVal(Arg6()) 
    } 
}
template<typename Arg0,
    typename Arg1,
    typename Arg2,
    typename Arg3,
    typename Arg4,
    typename Arg5,
    typename Arg6,
    typename Arg7>
std::vector<LuaVal> _createArgListFn()
{
    return { 
        LuaVal(Arg0()), 
        LuaVal(Arg1()), 
        LuaVal(Arg2()), 
        LuaVal(Arg3()), 
        LuaVal(Arg4()), 
        LuaVal(Arg5()), 
        LuaVal(Arg6()), 
        LuaVal(Arg7()) 
    } 
}
template<typename Arg0,
    typename Arg1,
    typename Arg2,
    typename Arg3,
    typename Arg4,
    typename Arg5,
    typename Arg6,
    typename Arg7,
    typename Arg8>
std::vector<LuaVal> _createArgListFn()
{
    return { 
        LuaVal(Arg0()), 
        LuaVal(Arg1()), 
        LuaVal(Arg2()), 
        LuaVal(Arg3()), 
        LuaVal(Arg4()), 
        LuaVal(Arg5()), 
        LuaVal(Arg6()), 
        LuaVal(Arg7()), 
        LuaVal(Arg8()) 
    } 
}
template<typename Arg0,
    typename Arg1,
    typename Arg2,
    typename Arg3,
    typename Arg4,
    typename Arg5,
    typename Arg6,
    typename Arg7,
    typename Arg8,
    typename Arg9>
std::vector<LuaVal> _createArgListFn()
{
    return { 
        LuaVal(Arg0()), 
        LuaVal(Arg1()), 
        LuaVal(Arg2()), 
        LuaVal(Arg3()), 
        LuaVal(Arg4()), 
        LuaVal(Arg5()), 
        LuaVal(Arg6()), 
        LuaVal(Arg7()), 
        LuaVal(Arg8()), 
        LuaVal(Arg9()) 
    } 
}
template<typename Arg0,
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
std::vector<LuaVal> _createArgListFn()
{
    return { 
        LuaVal(Arg0()), 
        LuaVal(Arg1()), 
        LuaVal(Arg2()), 
        LuaVal(Arg3()), 
        LuaVal(Arg4()), 
        LuaVal(Arg5()), 
        LuaVal(Arg6()), 
        LuaVal(Arg7()), 
        LuaVal(Arg8()), 
        LuaVal(Arg9()), 
        LuaVal(Arg10()) 
    } 
}
*/

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
        (*_callFn)(_fn, ret, args);
    }

    int ArgCount() { return _argCount; }
    std::vector<LuaVal> Args() { return _createArgList(); }
    
    template<typename... Args>
    LuaFunc(void (*fn)(Args... args))
    {
        _fn = (void (*)(void))fn;
        _callFn = &_luaCallNR<Args...>;
        _argCount = sizeof...(Args);
        _createArgList = &_createArgListFn<int, Args...>;
    }
    template<typename Ret, typename... Args>
    LuaFunc(Ret (*fn)(Args... args))
    {
        _fn = (void (*)(void))fn;
        _callFn = &_luaCallR<Ret, Args...>;
        _argCount = sizeof...(Args);
        _createArgList = &_createArgListFn<int, Args...>;
    }
private:
    std::vector<LuaVal> (*_createArgList)();

    void (*_fn)(void);
    void (*_callFn)(void (*)(void), LuaVal&, std::vector<LuaVal>&);
    int _argCount;
};

}

#endif
