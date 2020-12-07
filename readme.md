# C++ project - K-means clustering 

[1. Summary ](#1-summary)
[2. Implementation Detais](#2-implementation-details)
[3. Showcase](#3-showcase)
[3.1 Main Dataset](#31-main-dataset)
[3.2 Test Dataset](#32-test-dataset)
[References](#references)

## 1. Summary 

This project aims to implement a K-means clustering algorithm. K-means clustering is one of the popular unsupervised machine learning algorithms.

This algorithm identifies the k number of centroids and then allocates every data point to the nearest cluster while keeping them as small as possible.

The ‘means’ in the K-means refers to averaging the data, finding the centroid.

In this project, I will use cluster analysis to generate a big picture model of the weather at a local station using minute-granularity data.

The final result is a set of clusters, where each group differs from the other group, and the items inside each group are similar. 

## 2. Implementation details

K-means algorithm in data mining starts with a first group of randomly selected centroids, which are used as the beginning points for every group, and then performs repetitive calculations to optimize the positions of the centroids.

So, my main algorithm is:

1. **Choose the number of clusters k**

   The first step in K-means is to pick the number of clusters, k (user's choice).

2. **Select k random points from the data as centroids**

   The program randomly selects the centroid for each group

3. **Assign all the points to the closest cluster centroid**

   Once the program has initialized the centroids, it assigns each point to the closest cluster centroid.  The distance between centroid and point has been computed based on the straight line's length drawn between them. This is commonly referred to as the Euclidean distance. The most common definition is with Euclidean distance, minimizing the Sum of Squared Error (SSE) function

4. **Recompute the centroids of newly formed clusters**

   It has assigned all of the points to either cluster. The next step is to compute the centroids of newly formed clusters. So, program calculates the mean values of the clusters created and the new centroid values will these mean values and centroid is moved 

5. **Repeat steps 3 and 4**

   This process has to be repeated until we find a constant value for centroids and the latest cluster will be considered as the final cluster solution. So here are stopping criteria:

   - Points remain in the same group;
   - Maximum number of iterations are reached (maximum 100 in my program)

The algorithm described above finds the clusters and data set labels for a particular pre-chosen K. To find the number of clusters in the data, the user needs to run the K-means clustering algorithm for a range of K values and compare the results. In general, there is no method for determining exact value of K.

## 3. Showcase

To run the program following command line arguments must be specified:

1. File name with data of you are working
2. How many clusters you want to have in results (in our program minimum is 1 and maximum - 100)

The choice of a number of clusters entirely depends on you, and there is no right number that will always give you satisfactory results. Different quantities of groups lead to different clusters.

### 3.1. Main Dataset

The main data that I have used is `minute_weather_normilized.txt` in data folder.  It's a txt file with 60,000 rows, taken from Kaggle (https://www.kaggle.com/julianjose/minute-weather), which are normalized.

The columns we used from the Kaggle dataset are: 
`'air_pressure', 'air_temp', 'avg_wind_direction', 'avg_wind_speed','max_wind_direction',
 'max_wind_speed', 'relative_humidity'`

Each row, or sample, consists of the following variables:

- **air_pressure**: air pressure measured at the timestamp (Unit: hectopascals)

- **air_temp**: air temperature measure at the timestamp (Unit: degrees Fahrenheit)

- **avg_wind_direction**: wind direction averaged over the minute before the timestamp (Unit: degrees, with 0 means coming from the North, and increasing clockwise)

- **avg_wind_speed**: wind speed averaged over the minute before the timestamp (Unit: meters per second)

- **max_wind_direction**: highest wind direction in the minute before the timestamp (Unit: degrees, with 0 being North and increasing clockwise)

- **max_wind_speed**: highest wind speed in the minute before the timestamp (Unit: meters per second)

- **relative_humidity**: relative humidity measured at the timestamp (Unit: percent)

So, as example it can be:
```
-1.438132831940401202e+00 2.578829473864047150e-01 -6.741740838359395749e-01 -7.572725498651992071e-01 -6.029934935199194879e-01 -7.386064222970766258e-01 4.653964194750106476e-01
-1.438132831940401202e+00 5.061586854072692987e-02 -1.885949232193531444e-01 -7.572725498651992071e-01 4.787118318134601924e-02 -6.537753351566094606e-01 -3.772811416985888955e-01
-1.470584283476086496e+00 1.394446166174457269e-01 -6.431796693284979050e-01 -3.601176287024053790e-01 -4.322748897949973967e-01 -3.568665301649746602e-01 3.811286633576506100e-01
-1.470584283476086496e+00 8.022545123296653813e-02 -7.361629128508229147e-01 -3.601176287024053790e-01 -6.350032317183423869e-01 -3.992820737352082427e-01 3.658072531544943051e-01
```

If you want to use a K-means clustering on `minute_weather_normilized.txt` input file, creating 8 clusters the following command is required:

`./main.exe "data/minute_weather_normilized.txt" 8`

Regarding the full results, full result of running the program can be found in `results` folder. 
Partial output of the program is presented below:

```
Data loaded successfully!
Groups initialized = 8

Starting K-Means Clustering algorithm..
Iteration - 1/100
Iteration - 2/100
Iteration - 3/100
Iteration - 4/100
Iteration - 5/100
...
Cluster 6 centroid : 1.71532 -0.179133 -0.912572 -0.213864 -0.842018 -0.196932 -1.03648 
Cluster 7 centroid : -0.0670987 0.896968 -1.25994 -0.52566 -1.1098 -0.542727 -0.713317 
Cluster 8 centroid : -0.20279 -1.0114 0.556128 -0.277006 0.533018 -0.265704 1.20463 
```

### 3.2 Test Dataset

Second dataset that can be used for testing purposes is `test_input.txt`. It is a set of random two-dimensional coordinates:

```
9 9
1 1
-1 -1
3 3
10 10
-2 -2
7 8
0.2 0
-1 0
6 10
```
File `test_result.txt` in results folder contains output of the program for test data.

To run the program again for test data and save output to a file, following command can be used:
`./main.exe "data/test_input.txt" 2 > results/test_result.txt`

Results for test data are:

```
Data loaded successfully!
Groups initialized = 2

Starting K-Means Clustering algorithm..
Iteration - 1/100
Iteration - 2/100
Iteration - 3/100
Iteration - 4/100
Clustering finished in iteration : 4

Vector IDs in group 1 : 1 5 7 10 

Vector IDs in group 2 : 8 3 6 9 2 4 

----------------------------

Cluster 1 centroid : 8 9.25 
Cluster 2 centroid : 0.0333333 0.166667 
```

As you can see, K-means clustering is an extensively used technique for data cluster analysis. It is easy to understand and explain to others. Furthermore, it delivers results quickly. However, its performance is usually not as competitive as those of the other sophisticated clustering techniques because slight variations in the data could lead to high variance.

## References

1. https://towardsdatascience.com/understanding-k-means-clustering-in-machine-learning-6a6e67336aa1
1. https://www.analyticsvidhya.com/blog/2019/08/comprehensive-guide-k-means-clustering/
1. https://stanford.edu/~cpiech/cs221/handouts/kmeans.html
1. https://www.kaggle.com/julianjose/minute-weather
1. https://www.datasciencecentral.com/profiles/blogs/steps-to-calculate-centroids-in-cluster-using-k-means-clustering
1. https://blogs.oracle.com/datascience/introduction-to-k-means-clustering
