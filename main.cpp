#include <iostream>
#include <vector>
#include <sstream>

#include "data_loader.h"
#include "app_constants.h"
#include "vector.h"
#include "group.h"
#include "kmeans.h"

using namespace std;

int main(int argc, char **argv)
{
    long long unsigned int K;
    vector<Vector> all_data;

    //Load date from file
    DataLoader loader;
    all_data = loader.load(argc, argv, K);

    //Running K-Means Clustering
    KMeans kmeans(K, AppConstants::NUMBER_OF_ITERATIONS);
    kmeans.run(all_data);

    return 0;
}