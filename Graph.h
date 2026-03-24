//So we have declared a graph class which is storing the floor plan of building as a weighted undirected graph using adjacency matrix.

//We are using adjacency matrix so that:
//=>We can read and write in the graph in O(1) time.
//=>Block corridors in O(1) time
//Basically we can make changes in the graph in constant time.

//Space complexity will be O(v^2) but our building plan consists of small number of rooms or nodes so it will not cause any problem.

#ifndef GRAPH_H//prevents the header file from being included multiple times.

#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

class Graph{
private:
int number_of_nodes;
vector<vector<int>>adjacency_Matrix;
vector<string>node_name;

public:
Graph(int numNodes);
void addEdge(int u,int v,int wt);
void blockCorridor(int u,int v);

void setNodeName(string &name,int node);
string getNodeName(int node);

int getEdgeWt(int u,int v);
int getNumberOfNodes();

void printGraph();
};

#endif
