#ifndef Cluster_H
#define Cluster_H

#include <vector>

#include "vector.h"

using namespace std;

class Group
{
	private:
		int groupId;
		vector<double> centroid;
		vector<Vector> vectors;

	public:
		Group(int, Vector);

		void appendVector(Vector);

		bool removeVector(int);

		int getId();

		Vector getVector(int);

		int getSize();

		double getCentroidByPos(int);

		void setCentroidByPos(int pos, double);
};

// Overloaded operator + used to add point to cluster
Group operator+(Group, Vector);

// Overloaded operator - used to remove a point from cluster
Group operator-(Group, int);

#endif