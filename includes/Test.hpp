
#ifndef __CPP_TEST__INCLUDES__TEST_HPP__
#define __CPP_TEST__INCLUDES__TEST_HPP__

#include <string>

#include "./Result.hpp"

namespace CppTest
{
    class Test
    {
    public:
        Test(std::string path, std::string name)
        {
            _name = name;
        }
        virtual ~Test() {}
        virtual void run(Result & result){}

        std::string name() { return _name; }

    private:
        std::string _context;
        std::string _name;
    };
};

#endif