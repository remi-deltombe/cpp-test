
#ifndef __CPP_TEST__INCLUDES__FACADE_HPP__
#define __CPP_TEST__INCLUDES__FACADE_HPP__

#include <string>

#include "./Pool.hpp"

namespace CppTest
{
    extern Pool _pool;
    void run(std::string context);
};

#endif
