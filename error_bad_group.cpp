#ifndef BadGroupEx_H
#define BadGroupEx_H

// using standard exceptions
#include <iostream>
#include <exception>
#include "app_constants.h"

using namespace std;

class BadGroupException: public exception
{
    virtual const char* what() const throw()
    {
        return AppConstants::ERROR_GROUP_COUNT_EXCEEDED;
    }
};

#endif