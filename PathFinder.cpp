#include<iostream>
#include"PathFinder.h"
#include<queue>
#include<limits.h>
#include<algorithm>
#include<functional>
using namespace std;

PathResult PathFinder::findShortestPath(Graph &graph,int source, int destination){
    int Vertices=graph.getNumberOfNodes();
    vector<int>distance(Vertices,INT_MAX);
    vector<int>parent(Vertices,-1);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    distance[source]=0;
    pq.push({0,source});
    while(!pq.empty()){
        auto p=pq.top();
        int d=p.first;
        int u=p.second;
        pq.pop();
        if(u==destination)break;
        if(d>distance[u])continue;
        for(int i=0;i<Vertices;i++){
                int weight=graph.getEdgeWt(u,i);
                if(weight==INT_MAX || weight==0)continue;

                if(distance[u]!=INT_MAX && distance[u]+weight<distance[i]){
                    distance[i]=distance[u]+weight;
                    parent[i]=u;
                    pq.push({distance[i],i});
                }
        }
    }
    PathResult result;
    result.distance=distance[destination];
    if(distance[destination]==INT_MAX)return result;
    int current=destination;
    while (current != -1) {
        result.path.push_back(current);
        current = parent[current];
    }
    reverse(result.path.begin(),result.path.end());
    return result;
}