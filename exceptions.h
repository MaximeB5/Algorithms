#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

// Includes
#include <exception>
#include <string>

namespace Algorithms {

/**
 * @brief The Exception class
 * Base exception class
 */
class Exception : public std::exception
{
private:
    std::string _msg;
public:
    Exception(const std::string& msg) : _msg(msg){}

    virtual const char* what() const noexcept override
    {
        return _msg.c_str();
    }
};

/**
 * @brief The UndefinedOperatorsException class
 */
class UndefinedOperatorException : public Exception {
public:
        UndefinedOperatorException(const std::string& msg) : Exception(msg) {};
        ~UndefinedOperatorException() throw () {};
};

/**
 * @brief The NotImplementedMethodException class
 */
class NotImplementedMethodException : public Exception {
public:
        NotImplementedMethodException(const std::string& msg) : Exception(msg) {};
        ~NotImplementedMethodException() throw () {};
};

}

#endif // EXCEPTIONS_H
