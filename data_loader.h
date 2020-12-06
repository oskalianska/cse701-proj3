#ifndef PointsLoader_H
#define PointsLoader_H

#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

#include "vector.h"

using namespace std;

#define BASE 10

class DataLoader
{
	public:
		vector<Vector> load(int, char **, long long unsigned int &);
};

#endif