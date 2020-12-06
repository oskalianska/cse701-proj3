#ifndef KMeans_H
#define KMeans_H

#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

#include "app_constants.h"
#include "group.h"
#include "vector.h"
#include "error_bad_group.cpp"

using namespace std;

class KMeans
{
	private:
		int K, iterations, dim, vectors_count;
    
		vector<Group> groups;

		int getNearestGroupId(Vector);

	public:
		KMeans(int, int);

		void run(vector<Vector>&);
};

#endif