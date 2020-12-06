#include <cmath>

#include "kmeans.h"
#include "logger.h"

using namespace std;

int KMeans::getNearestGroupId(Vector v)
{
    double sum = 0.0, min_distance;
    int NearestClusterId;

    for(int i = 0; i < dim; i++)
    {
        sum += pow(groups[0].getCentroidByPos(i) - v.getVal(i), 2.0);
    }

    min_distance = sqrt(sum);
    NearestClusterId = groups[0].getId();

    for(int i = 1; i < K; i++)
    {
        double dist;
        sum = 0.0;

        for(int j = 0; j < dim; j++)
        {
            sum += pow(groups[i].getCentroidByPos(j) - v.getVal(j), 2.0);
        }

        dist = sqrt(sum);

        if(dist < min_distance)
        {
            min_distance = dist;
            NearestClusterId = groups[i].getId();
        }
    }

    return NearestClusterId;
}

KMeans::KMeans(int K, int iterations)
{
    this->K = K;
    this->iterations = iterations;
}

void KMeans::run(vector<Vector>& all_data)
{
    vectors_count = all_data.size();
    dim = all_data[0].getDim();

    //Initializing Clusters
    vector<int> used_vectorIds;

    for(int i=1; i<=K; i++)
    {
        while(true)
        {
            int index = rand() % vectors_count;

            if(find(used_vectorIds.begin(), used_vectorIds.end(), index) == used_vectorIds.end())
            {
                used_vectorIds.push_back(index);
                all_data[index].setGroup(i);
                Group cluster(i, all_data[index]);
                groups.push_back(cluster);
                break;
            }
        }
    }
    
    print<string, std::size_t>("Groups initialized = ", groups.size());
    print<string>("");

    print<string>("Starting K-Means Clustering algorithm..");

    int iteration = 1;
    while(true)
    {
        cout<<"Iteration - "<<iteration<<"/"<<iterations<<endl;
        bool done = true;

        // Add all points to their nearest cluster
        for(int i = 0; i < vectors_count; i++)
        {
            int currentGroupId = all_data[i].getGroup();
            int nearestGroupId = getNearestGroupId(all_data[i]);

            if(currentGroupId != nearestGroupId)
            {
                if(currentGroupId != 0){
                    for(int j=0; j<K; j++){
                        if(groups[j].getId() == currentGroupId){
                            // use overloaded operator "-" for cluster class
                            groups[j] = groups[j] - all_data[i].getID();
                        }
                    }
                }

                for(int j=0; j<K; j++){
                    if(groups[j].getId() == nearestGroupId){
                        // use overloaded operator "+" for cluster class
                        groups[j] = groups[j] + all_data[i];
                    }
                }
                all_data[i].setGroup(nearestGroupId);
                done = false;
            }
        }

        // Recalculating the center of each cluster
        for(int i = 0; i < K; i++)
        {
            int groupSize = groups[i].getSize();

            for(int j = 0; j < dim; j++)
            {
                double sum = 0.0;
                if(groupSize > 0)
                {
                    for(int p = 0; p < groupSize; p++)
                        sum += groups[i].getVector(p).getVal(j);
                    groups[i].setCentroidByPos(j, sum / groupSize);
                }
            }
        }

        if(done || iteration >= iterations)
        {
            print<string, int>("Clustering finished in iteration : ", iteration);
            print<string>("");

            break;
        }
        iteration++;
    }

    //Print pointIds in each cluster
    for(int i=0; i<K; i++)
	{
        cout<<"Vector IDs in group "<<groups[i].getId()<<" : ";
        for(int j=0; j<groups[i].getSize(); j++){
            cout<<groups[i].getVector(j).getID()<<" ";
        }
        cout<<endl<<endl;
    }

    print<string>("----------------------------");
    print<string>("");

    //Write cluster centers 
    for(int i=0; i<K; i++)
	{
        cout<<"Cluster "<<groups[i].getId()<<" centroid : ";
        for(int j=0; j<dim; j++)
		{
            cout<<groups[i].getCentroidByPos(j)<<" ";
        }
        print<string>("");
    }
}