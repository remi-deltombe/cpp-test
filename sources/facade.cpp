
#include "./../includes/facade.hpp"
#include "./../includes/Pool.hpp"
#include <iostream>

CppTest::Pool Test::_pool;

void CppTest::run(std::string context)
{
    _pool.run();
}