
#ifndef __CPP_TEST__INCLUDES__EXPECTATIONS_HPP__
#define __CPP_TEST__INCLUDES__EXPECTATIONS_HPP__

#include <string>
#include <vector>
#include <sstream>

namespace CppTest
{
    class AbstractExpectation
    {
    public:
        struct Comparaison
        {
            bool _result;
            int _line;
            std::string _file;
            std::string _message;
        };

        std::vector<Comparaison> _comparaisons;
        std::string _name;
    };

    template<typename T>
    class Expectation : public AbstractExpectation
    {
    public:
        Expectation(std::string name, T value)
        {
            _name = name;
            _value = value;
        }

        template<typename C>
        Expectation & toBe(std::string file, int line, C value)
        {
            bool result;
            std::string message;

            try
            {
                _comparaisons.push_back({ 
                    _value == value, 
                    line,
                    file,
                    std::string("[") + stringify(_value) + "] is not equal to [" + stringify(value) + "]"
                });
            }
            catch(...)
            {
                _comparaisons.push_back({ 
                    false, 
                    line,
                    file,
                    "Values are not comparable"
                });
            }

            return *this;
        }

        template<typename C>
        Expectation & toNotBe(std::string file, int line, C value)
        {
            bool result;
            std::string message;

            try
            {
                _comparaisons.push_back({ 
                    _value != value, 
                    line,
                    file,
                    std::string("[") + stringify(_value) + "] is not different of [" + stringify(value) + "]"
                });
            }
            catch(...)
            {
                _comparaisons.push_back({ 
                    false, 
                    line,
                    file,
                    "Values are not comparable"
                });
            }

            return *this;
        }

        Expectation & toBeNull(std::string file, int line)
        {
            bool result;
            std::string message;

            try
            {
                _comparaisons.push_back({ 
                    _value == nullptr, 
                    line,
                    file,
                    "Value is not null"
                });
            }
            catch(...)
            {
                _comparaisons.push_back({ 
                    false, 
                    line,
                    file,
                    "Values are not comparable"
                });
            }

            return *this;
        }

        Expectation & toNotBeNull(std::string file, int line)
        {
            bool result;
            std::string message;

            try
            {
                _comparaisons.push_back({ 
                    _value != nullptr, 
                    line,
                    file,
                    "Value is null"
                });
            }
            catch(...)
            {
                _comparaisons.push_back({ 
                    false, 
                    line,
                    file,
                    "Values are not comparable"
                });
            }

            return *this;
        }

    private:
        T _value;

        template<typename C>
        std::string stringify(C v)
        {
            std::string s;
            std::stringstream str;
            str << v;
            str >> s;
            return s;
        }
    };
};

#endif