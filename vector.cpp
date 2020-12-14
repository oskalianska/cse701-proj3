#include "vector.h"
#include "error_bad_group.cpp"
#include "logger.h"

// Vector class ensures that the group id is always in a range from 0 to 100 (invariant) is always satisfied in
// constructors, by making it private, any member function which changes the data does it safely

using namespace std;


Vector::Vector(const int id, const string line)
{
    dim = 0;
    vectorId = id;
    stringstream is(line);
    double val;
    while(is >> val)
	{
        values.push_back(val);
        dim++;
    }
    groupId = 0; // Initially not assigned to any group
}

int Vector::getDim()
{
    return dim;
}

int Vector::getGroup()
{
    return groupId;
}

int Vector::getID()
{
    return vectorId;
}

void Vector::setGroup(int val)
{
    if (val < AppConstants::MIN_GROUPS || val > AppConstants::MAX_GROUPS)
    {
        throw BadGroupException();
    }

    groupId = val;
}

double Vector::getVal(int pos)
{
    return values[pos];
}
