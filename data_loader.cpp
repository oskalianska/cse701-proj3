#include "data_loader.h"
#include "logger.h"

using namespace std;

vector<Vector> DataLoader::load(int argc, char **argv, long long unsigned int &K)
{
    //Need 2 arguments (except filename) to run, else exit
    if(argc != 3)
	{
        throw std::invalid_argument("Program requires two arguments.");
    }

    char *stopstring;
    //Fetching number of groups
    K = strtoull(argv[2], &stopstring, BASE);

    //Open file for fetching vectors
    string filename = argv[1];
    ifstream infile(filename.c_str());

    if(!infile.is_open())
	{
        throw std::runtime_error("Unable to open file.");
    }

    //Fetching points from file
    int vectorId = 1;
    vector<Vector> all_vectors;
    string line;

    while(getline(infile, line))
	{
        Vector point(vectorId, line);
        all_vectors.push_back(point);
        vectorId++;
    }

    infile.close();
    print<string>("\nData loaded successfully!");

    //Return if number of groups > number of points
    if(all_vectors.size() < K)
	{
        throw std::invalid_argument("Number of groups greater than number of vectors.");
    }

    if(all_vectors.size() == 0)
	{
        throw std::invalid_argument("File does not contain any data.");
    }

    //All points must have same dimensions
    int dim = all_vectors[0].getDim();

    if (!all_of(all_vectors.begin(), all_vectors.end(), [dim](Vector p) { return p.getDim() == dim; } ))
    {
        throw std::invalid_argument("Input vectors have different dimentions");
    }

    return all_vectors;
}
