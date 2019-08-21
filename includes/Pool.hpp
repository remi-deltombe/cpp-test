
#ifndef __CPP_TEST__INCLUDES__POOL_HPP__
#define __CPP_TEST__INCLUDES__POOL_HPP__

#include <vector>
#include <memory>
#include <iostream>

#include "./Test.hpp"
#include "./Result.hpp"

namespace CppTest
{
    class Pool
    {
    public:
        template<class T>
        void addTest()
        {
            _tests.push_back(std::make_unique<T>());
        }

        void run()
        {
            int i = 1; 
            std::cout << "Start testing -----" << std::endl;
            for(auto & test : _tests)
            {
                std::cout << "[" << i++ << "/ " << _tests.size() << "] " << test->name() << " | ";
                Result result;
                test->run(result);
                std::cout << result.toString() << std::endl;
            }
            std::cout << "Test done" << std::endl;
        }

    private:
        std::vector<std::unique_ptr<Test::Test>> _tests;
    };
};

#endif