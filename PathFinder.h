#ifndef PATHFINDER_H
#include<iostream>
#include<vector>
#include"Graph.h"
using namespace std;

struct PathResult{
    int distance;
    vector<int>path;
};

class PathFinder{
public:
    static PathResult findShortestPath(Graph &graph,int source,int destination);
};

#endif