// This module implements the Graph class.

#include"Graph.h"
#include<iostream>
using namespace std;

Graph::Graph(int n){
    number_of_nodes=n;
    adjacency_Matrix.assign(n,vector<int>(n,0)); //Initialises our matrix with 0
    node_name.resize(n);
    for(int i=0;i<n;i++){
        node_name[i]="Node "+to_string(i);
    }
}

void Graph::addEdge(int u,int v,int wt){
    adjacency_Matrix[u][v]=wt;
    adjacency_Matrix[v][u]=wt;
}

void Graph::blockCorridor(int u,int v){
    adjacency_Matrix[u][v]=INT_MAX;
    adjacency_Matrix[v][u]=INT_MAX;
}

void Graph::setNodeName(string &name,int node){
        node_name[node]=name;
}

string Graph::getNodeName(int node){
    return node_name[node];
}


int Graph::getEdgeWt(int u,int v){
    return adjacency_Matrix[u][v];
}

int Graph::getNumberOfNodes(){
    return number_of_nodes;
}

void Graph::printGraph(){
    for(int i=0;i<number_of_nodes;i++){
        for(int j=0;j<number_of_nodes;j++){
            cout<<adjacency_Matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}