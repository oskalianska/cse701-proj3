#ifndef Point_H
#define Point_H

#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

class Vector
{
	private:
		int vectorId, groupId;
		int dim;
		vector<double> values;

	public:
		Vector(const int, const string);

		int getDim();

		int getGroup();

		int getID();

		void setGroup(int);

		double getVal(int);
};

#endif