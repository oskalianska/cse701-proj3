#include <iostream>
#include <vector>
#include <sstream>

#include "data_loader.h"
#include "app_constants.h"
#include "vector.h"
#include "group.h"
#include "kmeans.h"
#include "logger.h"
#include "error_bad_group.cpp"

using namespace std;

int main(int argc, char **argv)
{
    long long unsigned int K;
    vector<Vector> all_data;

    //Load date from file
    DataLoader loader;
    try
    {
        all_data = loader.load(argc, argv, K);
    }
    catch (const invalid_argument &e)
    {
        print<string>(e.what());
    }
    catch (const runtime_error &e)
    {
        print<string>("Can't open input file.");
    }

    //Running K-Means Clustering
    try
    {
        KMeans kmeans(K, AppConstants::NUMBER_OF_ITERATIONS);
        kmeans.run(all_data);
    }
    catch (const BadGroupException &e)
    {
        print<string>("Group number is invalid");
    }

    return 0;
}