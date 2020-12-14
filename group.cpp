#include "group.h"
#include "error_bad_group.cpp"
#include "logger.h"

using namespace std;

Group::Group(int groupId, Vector centroid)
{
    if (groupId < AppConstants::MIN_GROUPS || groupId > AppConstants::MAX_GROUPS)
    {
        throw BadGroupException();
    }
    this->groupId = groupId;

    for(int i=0; i<centroid.getDim(); i++)
	{
        this->centroid.push_back(centroid.getVal(i));
    }

    this->appendVector(centroid);
}

void Group::appendVector(Vector v)
{
    v.setGroup(this->groupId);
    vectors.push_back(v);
}

bool Group::removeVector(int vId)
{
    int size = vectors.size();

    for(int i = 0; i < size; i++)
    {
        if(vectors[i].getID() == vId)
        {
            vectors.erase(vectors.begin() + i);
            return true;
        }
    }
    return false;
}

int Group::getId()
{
    return groupId;
}

Vector Group::getVector(int pos)
{
    return vectors[pos];
}

int Group::getSize()
{
    return vectors.size();
}

double Group::getCentroidByPos(int pos) 
{
    return centroid[pos];
}

void Group::setCentroidByPos(int pos, double val)
{
    this->centroid[pos] = val;
}

Group operator+(Group g, Vector v)
{
	g.appendVector(v);
	return g;
}

Group operator-(Group g, int vectorId)
{
    g.removeVector(vectorId);
    return g;
}
