#ifndef AU_LUA_FUNC_H
#define AU_LUA_FUNC_H

#include "auluaval.h"

namespace Au{

template<typename T> using identity_t = T; // VS2013 hack

template<typename... Args>
std::vector<LuaVal> _createArgListFn()
{
    std::vector<LuaVal> v = {LuaVal(bare_type<Args>::type())...};
    v.erase(v.begin());
    return v;
}

class LuaFuncStore
{
public:
    template<typename Ret, typename... Args>
    struct Storage
    {
        static std::vector<Ret(*)(Args...)> functions;
        static Ret CallNR(int idx, Args... args)
        { functions[idx](args...); }
        static Ret CallR(int idx, Args... args)
        { return functions[idx](args...); }
    };
    
    template<typename Class, typename Ret, typename... Args>
    struct MStorage
    {
        static std::vector<Ret(Class::*)(Args...)> functions;
        static Ret CallNR(int idx, void* this_, Args... args)
        { (((Class*)this_)->*functions[idx])(args...); }
        static Ret CallR(int idx, void* this_, Args... args)
        { return (((Class*)this_)->*functions[idx])(args...); }
    };

    template<typename Ret, typename... Args>
    static int Store(Ret(*fn)(Args...))
    {
        int idx = Storage<Ret, Args...>::functions.size();
        Storage<Ret, Args...>::functions.push_back(fn);
        return idx;
    }
    
    template<typename Class, typename Ret, typename... Args>
    static int Store(Ret(Class::*fn)(Args...))
    {
        int idx = MStorage<Class, Ret, Args...>::functions.size();
        MStorage<Class, Ret, Args...>::functions.push_back(fn);
        return idx;
    }
    
    static void CallNR(int fnIdx, LuaVal& ret, std::vector<LuaVal>& args)
    { Storage<void>::CallNR(fnIdx); }
    template<typename Arg0>
    static void CallNR(int fnIdx, LuaVal& ret, std::vector<LuaVal>& args)
    { Storage<void, Arg0>::CallNR(fnIdx, args[0].Get<Arg0>()); }
    template<typename Arg0, 
        typename Arg1>
    static void CallNR(int fnIdx, LuaVal& ret, std::vector<LuaVal>& args)
    { 
        Storage<void, Arg0, Arg1>::CallNR(fnIdx,
            args[0].Get<Arg0>(), 
            args[1].Get<Arg1>()
        ); 
    }
    template<typename Arg0, 
        typename Arg1, 
        typename Arg2>
    static void CallNR(int fnIdx, LuaVal& ret, std::vector<LuaVal>& args)
    { 
        Storage<void, Arg0, Arg1, Arg2>::CallNR(fnIdx,
            args[0].Get<Arg0>(), 
            args[1].Get<Arg1>(), 
            args[2].Get<Arg2>()
        ); 
    }
    template<typename Arg0, 
        typename Arg1, 
        typename Arg2, 
        typename Arg3>
    static void CallNR(int fnIdx, LuaVal& ret, std::vector<LuaVal>& args)
    { 
        Storage<void, Arg0, Arg1, Arg2, Arg3>::CallNR(fnIdx,
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
    static void CallNR(int fnIdx, LuaVal& ret, std::vector<LuaVal>& args)
    { 
        Storage<void, Arg0, Arg1, Arg2, Arg3, Arg4>::CallNR(fnIdx,
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
    static void CallNR(int fnIdx, LuaVal& ret, std::vector<LuaVal>& args)
    { 
        Storage<void, Arg0, Arg1, Arg2, Arg3, Arg4, Arg5>::CallNR(fnIdx,
            args[0].Get<Arg0>(), 
            args[1].Get<Arg1>(), 
            args[2].Get<Arg2>(), 
            args[3].Get<Arg3>(), 
            args[4].Get<Arg4>(), 
            args[5].Get<Arg5>()
        ); 
    }
    
    template<typename Ret>
    static void CallR(int fnIdx, LuaVal& ret, std::vector<LuaVal>& args)
    { ret = Storage<Ret>::CallR(fnIdx); }
    template<typename Ret, typename Arg0>
    static void CallR(int fnIdx, LuaVal& ret, std::vector<LuaVal>& args)
    { ret = Storage<Ret, Arg0>::CallR(fnIdx, args[0].Get<Arg0>()); }
    template<typename Ret, typename Arg0, 
        typename Arg1>
    static void CallR(int fnIdx, LuaVal& ret, std::vector<LuaVal>& args)
    { 
        ret = Storage<Ret, Arg0, Arg1>::CallR(fnIdx, 
            args[0].Get<Arg0>(), 
            args[1].Get<Arg1>()
        ); 
    }
    template<typename Ret, typename Arg0, 
        typename Arg1, 
        typename Arg2>
    static void CallR(int fnIdx, LuaVal& ret, std::vector<LuaVal>& args)
    { 
        ret = Storage<Ret, Arg0, Arg1, Arg2>::CallR(fnIdx, 
            args[0].Get<Arg0>(), 
            args[1].Get<Arg1>(), 
            args[2].Get<Arg2>()
        ); 
    }
    template<typename Ret, typename Arg0, 
        typename Arg1, 
        typename Arg2, 
        typename Arg3>
    static void CallR(int fnIdx, LuaVal& ret, std::vector<LuaVal>& args)
    { 
        ret = Storage<Ret, Arg0, Arg1, Arg2, Arg3>::CallR(fnIdx, 
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
    static void CallR(int fnIdx, LuaVal& ret, std::vector<LuaVal>& args)
    { 
        ret = Storage<Ret, Arg0, Arg1, Arg2, Arg3, Arg4>::CallR(fnIdx, 
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
    static void CallR(int fnIdx, LuaVal& ret, std::vector<LuaVal>& args)
    { 
        ret = Storage<Ret, Arg0, Arg1, Arg2, Arg3, Arg4, Arg5>::CallR(fnIdx, 
            args[0].Get<Arg0>(), 
            args[1].Get<Arg1>(), 
            args[2].Get<Arg2>(), 
            args[3].Get<Arg3>(), 
            args[4].Get<Arg4>(), 
            args[5].Get<Arg5>()
        ); 
    }
    
    template<typename Class>
    static void CallMNR(int fnIdx, void* this_, LuaVal& ret, std::vector<LuaVal>& args)
    { MStorage<Class, void>::CallNR(fnIdx, this_); }
    template<typename Class, typename Arg0>
    static void CallMNR(int fnIdx, void* this_, LuaVal& ret, std::vector<LuaVal>& args)
    { MStorage<Class, void, Arg0>::CallNR(fnIdx, this_, args[0].Get<Arg0>()); }
    template<typename Class, typename Arg0, 
        typename Arg1>
    static void CallMNR(int fnIdx, void* this_, LuaVal& ret, std::vector<LuaVal>& args)
    { 
        MStorage<Class, void, Arg0, Arg1>::CallNR(fnIdx, this_, 
            args[0].Get<Arg0>(),
            args[1].Get<Arg1>()
        );
    }
    template<typename Class, typename Arg0, 
        typename Arg1, 
        typename Arg2>
    static void CallMNR(int fnIdx, void* this_, LuaVal& ret, std::vector<LuaVal>& args)
    { 
        MStorage<Class, void, Arg0, Arg1, Arg2>::CallNR(fnIdx, this_, 
            args[0].Get<Arg0>(), 
            args[1].Get<Arg1>(), 
            args[2].Get<Arg2>()
        ); 
    }
    template<typename Class, typename Arg0, 
        typename Arg1, 
        typename Arg2, 
        typename Arg3>
    static void CallMNR(int fnIdx, void* this_, LuaVal& ret, std::vector<LuaVal>& args)
    { 
        MStorage<Class, void, Arg0, Arg1, Arg2, Arg3>::CallNR(fnIdx, this_, 
            args[0].Get<Arg0>(), 
            args[1].Get<Arg1>(), 
            args[2].Get<Arg2>(), 
            args[3].Get<Arg3>()
        ); 
    }
    template<typename Class, typename Arg0, 
        typename Arg1, 
        typename Arg2, 
        typename Arg3, 
        typename Arg4>
    static void CallMNR(int fnIdx, void* this_, LuaVal& ret, std::vector<LuaVal>& args)
    { 
        MStorage<Class, void, Arg0, Arg1, Arg2, Arg3, Arg4>::CallNR(fnIdx, this_, 
            args[0].Get<Arg0>(), 
            args[1].Get<Arg1>(), 
            args[2].Get<Arg2>(), 
            args[3].Get<Arg3>(), 
            args[4].Get<Arg4>()
        ); 
    }
    template<typename Class, typename Arg0, 
        typename Arg1, 
        typename Arg2, 
        typename Arg3, 
        typename Arg4, 
        typename Arg5>
    static void CallMNR(int fnIdx, void* this_, LuaVal& ret, std::vector<LuaVal>& args)
    { 
        MStorage<Class, void, Arg0, Arg1, Arg2, Arg3, Arg4, Arg5>::CallNR(fnIdx, this_, 
            args[0].Get<Arg0>(), 
            args[1].Get<Arg1>(), 
            args[2].Get<Arg2>(), 
            args[3].Get<Arg3>(), 
            args[4].Get<Arg4>(), 
            args[5].Get<Arg5>()
        ); 
    }
    
    template<typename Class, typename Ret>
    static void CallMR(int fnIdx, void* this_, LuaVal& ret, std::vector<LuaVal>& args)
    { ret = MStorage<Class, Ret>::CallR(fnIdx, this_); }
    template<typename Class, typename Ret, typename Arg0>
    static void CallMR(int fnIdx, void* this_, LuaVal& ret, std::vector<LuaVal>& args)
    { ret = MStorage<Class, Ret, Arg0>::CallR(fnIdx, this_, args[0].Get<Arg0>()); }
    template<typename Class, typename Ret, typename Arg0, 
        typename Arg1>
    static void CallMR(int fnIdx, void* this_, LuaVal& ret, std::vector<LuaVal>& args)
    { 
        ret = MStorage<Class, Ret, Arg0, Arg1>::CallR(fnIdx, this_, 
            args[0].Get<Arg0>(),
            args[1].Get<Arg1>()
        );
    }
    template<typename Class, typename Ret, typename Arg0, 
        typename Arg1, 
        typename Arg2>
    static void CallMR(int fnIdx, void* this_, LuaVal& ret, std::vector<LuaVal>& args)
    { 
        ret = MStorage<Class, Ret, Arg0, Arg1, Arg2>::CallR(fnIdx, this_, 
            args[0].Get<Arg0>(), 
            args[1].Get<Arg1>(), 
            args[2].Get<Arg2>()
        ); 
    }
    template<typename Class, typename Ret, typename Arg0, 
        typename Arg1, 
        typename Arg2, 
        typename Arg3>
    static void CallMR(int fnIdx, void* this_, LuaVal& ret, std::vector<LuaVal>& args)
    { 
        ret = MStorage<Class, Ret, Arg0, Arg1, Arg2, Arg3>::CallR(fnIdx, this_, 
            args[0].Get<Arg0>(), 
            args[1].Get<Arg1>(), 
            args[2].Get<Arg2>(), 
            args[3].Get<Arg3>()
        ); 
    }
    template<typename Class, typename Ret, typename Arg0, 
        typename Arg1, 
        typename Arg2, 
        typename Arg3, 
        typename Arg4>
    static void CallMR(int fnIdx, void* this_, LuaVal& ret, std::vector<LuaVal>& args)
    { 
        ret = MStorage<Class, Ret, Arg0, Arg1, Arg2, Arg3, Arg4>::CallR(fnIdx, this_, 
            args[0].Get<Arg0>(), 
            args[1].Get<Arg1>(), 
            args[2].Get<Arg2>(), 
            args[3].Get<Arg3>(), 
            args[4].Get<Arg4>()
        ); 
    }
    template<typename Class, typename Ret, typename Arg0, 
        typename Arg1, 
        typename Arg2, 
        typename Arg3, 
        typename Arg4, 
        typename Arg5>
    static void CallMR(int fnIdx, void* this_, LuaVal& ret, std::vector<LuaVal>& args)
    { 
        ret = MStorage<Class, Ret, Arg0, Arg1, Arg2, Arg3, Arg4, Arg5>::CallR(fnIdx, this_, 
            args[0].Get<Arg0>(), 
            args[1].Get<Arg1>(), 
            args[2].Get<Arg2>(), 
            args[3].Get<Arg3>(), 
            args[4].Get<Arg4>(), 
            args[5].Get<Arg5>()
        ); 
    }
};
template<typename Ret, typename... Args>
std::vector<Ret(*)(Args...)> LuaFuncStore::Storage<Ret, Args...>::functions;
template<typename Class, typename Ret, typename... Args>
std::vector<Ret(Class::*)(Args...)> LuaFuncStore::MStorage<Class, Ret, Args...>::functions;

class LuaFunc
{
public:
    void operator()(LuaVal& ret, std::vector<LuaVal>& args)
    { (*_callFn)(_fnIndex, ret, args); }
    
    void operator()(void* this_, LuaVal& ret, std::vector<LuaVal>& args)
    { (*_callMFn)(_mfnIndex, this_, ret, args); }

    int ArgCount() { return _argCount; }
    std::vector<LuaVal> Args() { return _createArgList(); }
    bool IsMember() { return _isMember; }
    
    template<typename... Args>
    LuaFunc(void (*fn)(Args... args))
    : _isMember(false)
    {
        _fnIndex = LuaFuncStore::Store(fn);
        _callFn = &LuaFuncStore::CallNR<Args...>;
        _argCount = sizeof...(Args);
        _createArgList = &_createArgListFn<int, Args...>;
    }
    template<typename Ret, typename... Args>
    LuaFunc(Ret (*fn)(Args... args))
    : _isMember(false)
    {
        _fnIndex = LuaFuncStore::Store(fn);
        _callFn = &LuaFuncStore::CallR<Ret, Args...>;
        _argCount = sizeof...(Args);
        _createArgList = &_createArgListFn<int, Args...>;
    }
    
    template<typename Class, typename... Args>
    LuaFunc(void (Class::*fn)(Args... args))
    : _isMember(true)
    {
        _mfnIndex = LuaFuncStore::Store(fn);
        _callMFn = &LuaFuncStore::CallMNR<Class, Args...>;
        _argCount = sizeof...(Args);
        _createArgList = &_createArgListFn<int, Args...>;
    }
    template<typename Class, typename Ret, typename... Args>
    LuaFunc(Ret (Class::*fn)(Args... args))
    : _isMember(true)
    {
        _mfnIndex = LuaFuncStore::Store(fn);
        _callMFn = &LuaFuncStore::CallMR<Class, Ret, Args...>;
        _argCount = sizeof...(Args);
        _createArgList = &_createArgListFn<int, Args...>;
    }
private:
    std::vector<LuaVal> (*_createArgList)();
    
    bool _isMember;
    
    int _fnIndex;
    int _mfnIndex;

    void (*_callFn)(int fnIdx, LuaVal&, std::vector<LuaVal>&);
    void (*_callMFn)(int fnIdx, void* this_, LuaVal&, std::vector<LuaVal>&);
    int _argCount;
};

}

#endif
