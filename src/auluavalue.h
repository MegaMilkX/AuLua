#ifndef AU_LUA_VAL_H
#define AU_LUA_VAL_H

namespace Au{

class LuaValue
{
public:
    LuaValue()
    : _data(0) {}
    
    template<typename T>
    LuaValue(T& value)
    : _data(&value) {}

    template<typename T>
    LuaValue& operator=(T& value)
    {
        _data = &value;
        return *this;
    }
    
    template<typename T>
    T& Get()
    {
        return *(T*)_data;
    }
private:
    void* _data;
};

}

#endif
