
#ifndef __CPP_TEST__INCLUDES__RESULT_HPP__
#define __CPP_TEST__INCLUDES__RESULT_HPP__

#include <string>
#include <memory>

#include "./Expectation.hpp"

namespace CppTest
{
    class Result
    {
    public:
        template<typename T>
        Expectation<T> & expect(std::string name, T value)
        {
            Expectation<T> * expectation = new Expectation<T>(name, value);
            _expectations.push_back(expectation);
            return *expectation;
        }

        std::string toString()
        {
            std::string result = "";
            std::string errors = "";

            double failed = 0;
            double succeed = 0;

            for(auto expectation : _expectations)
            {
                for(auto comparaison : expectation->_comparaisons)
                {
                    if(comparaison._result)
                    {
                        succeed++;
                    }
                    else
                    {
                        failed++;
                        result += "\n    " + comparaison._file + "@" + std::to_string(comparaison._line) + " " + comparaison._message; 
                    }
                }
            }
            double total = succeed + failed;

            if(total > 0)
            {
                result = "total : " 
                    + std::to_string((int)total) 
                    + " / succeed : " 
                    + std::to_string((int)succeed) 
                    + " (" + std::to_string((int)(100.0*succeed/total))+ "%)"
                    +" / failed : " 
                    + std::to_string((int)failed)
                    + " (" + std::to_string((int)(100.0*failed/total))+ "%)"
                     + result;  
            }
            else
            {
                result = "total : 0";
            }

            return result;
        }

    private:
        std::vector<AbstractExpectation*> _expectations;
        std::string _name;
    };
};

#endif