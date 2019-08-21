
#ifndef __CPP_TEST__MACROS__ALIASES_HPP__
#define __CPP_TEST__MACROS__ALIASES_HPP__

#include "./../includes/Test.hpp"
#include "./../includes/Result.hpp"
#include "./../includes/Register.hpp"

#define CONCAT(a, b) a ## b
#define EXPECT(value) __test__result__.expect(#value, value)
#define TO_BE(value) toBe(__FILE__, __LINE__, value)
#define TO_NOT_BE(value) toNotBe(__FILE__, __LINE__, value)
#define TO_BE_NULL() toBeNull(__FILE__, __LINE__)
#define TO_NOT_BE_NULL() toNotBeNull(__FILE__, __LINE__)

#define TO_BE_TRUE() TO_BE(true)
#define TO_BE_FALSE() TO_BE(false)


#define _TEST(description, runner, line)\
    class CONCAT(_test_,line) : public Test::Test\
    {\
    public:\
        CONCAT(_test_,line) () : Test::Test(__FILE__, description){}\
        void run(Test::Result & __test__result__)\
        {\
            runner\
        }\
    };\
    Test::Register<CONCAT(_test_,line)> CONCAT(_register_,line);

#define TEST(description, runner) _TEST(description, runner, __LINE__)

#endif