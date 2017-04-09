#ifndef AU_LUA_VAL_H
#define AU_LUA_VAL_H

#include "auluatype.h"

#include <iostream>


namespace Au{

template<typename T>
void _deleteFn(void*& val)
{ delete ((T*)val); val = 0; }
template<typename T>
void _copyFn(void*& to, const void* from)
{
    to = (void*)new T();
    (*(T*)to) = *(T*)from;
}
template<typename T>
void _printLuaValFn(void* data)
{
    std::cout << "Type: " << typeid(T).name() << std::endl;
    std::cout << "Data: " << data << std::endl;
}

class LuaVal
{
public:
    LuaVal()
    : _delete(0),
      _copy(0),
      _print(0),
      _data(0)
    {
    }
    
    template<typename T>
    LuaVal(const T& value)
    : _delete(0),
      _copy(0),
      _print(0),
      _data(0)
    { (*this) = (T)value; }
    
    LuaVal(const LuaVal& other)
    : _delete(0),
      _copy(0),
      _print(0),
      _data(0)
    { (*this) = other; }
    
    LuaVal& operator=(const LuaVal& other)
    {
        if(!other._data)
            return *this;
        if(_delete)
        {
            _delete(_data);
        }
        _delete = other._delete;
        _copy = other._copy;
        _print = other._print;
        _name = other._name;
        _type = other._type;
        other._copy(_data, other._data);
        return *this;
    }
    
    ~LuaVal()
    { if(_delete) _delete(_data); }
    
    int TypeIndex() { return _type._typeIndex; }
    
    template<typename T>
    LuaVal& operator=(const T& value)
    {
        if(_delete) _delete(_data);
        _delete = &_deleteFn<T>;
        _copy = &_copyFn<T>;
        _type = LuaType::Get<T>();
        
        _print = _printLuaValFn<T>;
        
        _data = (void*)new T();
        (*(T*)_data) = value;
        return *this;
    }
    
    template<typename T>
    typename bare_type<T>::type Get()
    {
        if(_type._typeIndex != LuaTypeIndex<bare_type<T>::type>())
        {
            return bare_type<T>::type();
        }
        
        return *(bare_type<T>::type*)_data;
    }
    
    void Print()
    {
        if(_print) 
            _print(_data);
        else
            std::cout << "EMPTY LuaVal" << std::endl;
    }
    
    void LuaPush(lua_State* L) const
    { _type.LuaPush(L, _data); }
    void LuaPop(lua_State* L)
    { _type.LuaPop(L, _data); }
private:
    void (*_delete)(void*&);
    void (*_copy)(void*&, const void*);
    void (*_print)(void*);
    
    std::string     _name;
    void*           _data;
    LuaType         _type;
};

}

#endif
