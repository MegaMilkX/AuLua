#include "auluavalue.h"

#include <iostream>
#include <string>

int main()
{
    int foo = 66;
    double* bar = new double(12.3);
    
    Au::LuaValue val;
    val = foo;
    std::cout << val.Get<int>() << std::endl;
    std::cout << *val.Get<int*>() << std::endl;
    val = bar;
    std::cout << val.Get<double>() << std::endl;
    std::cout << *val.Get<double*>() << std::endl;
    std::getchar();
    return 0;
}