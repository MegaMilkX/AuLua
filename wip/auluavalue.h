#ifndef AU_LUA_VAL_H
#define AU_LUA_VAL_H

namespace Au{
    
template<typename T> struct bare_type { typedef T type; };
template<typename T> struct bare_type<const T> : bare_type<T> {};
template<typename T> struct bare_type<T&> : bare_type<T> {};
template<typename T> struct bare_type<T&&> : bare_type<T> {};

class LuaValue
{
public:
    LuaValue()
    : _data(0) {}
    
    template<typename T>
    LuaValue(T& value)
    : _data(&value) {}
    
    template<typename T>
    LuaValue(T* value)
    : _data(value) {}

    template<typename T>
    LuaValue& operator=(T& value)
    {
        _data = &value;
        return *this;
    }
    
    template<typename T>
    LuaValue& operator=(T* value)
    {
        _data = value;
        return *this;
    }
    
    template<typename T>
    struct Getter
    {
        static T& Get(void* data)
        {
            return *(T*)data;
        }
    };
    
    template<typename T>
    struct Getter<T*>
    {
        static T*& Get(void*& data)
        {
            return (T*&)data;
        }
    };
    
    template<typename T>
    T& Get()
    { return Getter<bare_type<T>::type>::Get(_data); }
private:
    void* _data;
};

}

#endif
