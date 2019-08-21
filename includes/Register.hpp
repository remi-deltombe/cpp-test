
#ifndef __CPP_TEST__INCLUDES__REGISTER_HPP__
#define __CPP_TEST__INCLUDES__REGISTER_HPP__

#include <iostream>
#include "./facade.hpp"

namespace CppTest
{
    template<class T >
    class Register
    {
    public:
        Register()
        {
            _pool.addTest<T>();
        }
    };
};

#endif