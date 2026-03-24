#include<iostream>
#include"PathFinder.h"
#include<string>
#include<fstream>
using namespace std;

void printPath(Graph &graph,PathResult &result,const string &label){
cout<<label<<endl;
if(result.path.empty()){
    cout<<"Path not found"<<endl;
}
cout<<"Shortest distance:"<<result.distance<<endl;
cout<<"Route:";

//This is printing the path for better understanding.
for(int i=0;i<result.path.size();i++){
    cout<<graph.getNodeName(result.path[i]);
    if(i+1<result.path.size())cout<<"-->";
}
cout<<"\n";
cout<<"Step by step\n";
for(int i=0;i+1<result.path.size();i++){
    int u=result.path[i];
    int v=result.path[i+1];
    cout<<i+1<<". "<<graph.getNodeName(u)<<"--("<<graph.getEdgeWt(u,v)<<")-->"<<graph.getNodeName(v)<<endl;
}
}
int main(){
    ifstream fin("input.txt");   
    int number_of_nodes;
    fin >> number_of_nodes;
    Graph building(number_of_nodes);
    string name;
    getline(fin, name); 
    for(int i = 0; i < number_of_nodes; i++){
        getline(fin, name);
        building.setNodeName(name, i);
    }
    int edges;
    fin >> edges;
    for(int i = 0; i < edges; i++){
        int u, v, w;
        fin >> u >> v >> w;
        building.addEdge(u, v, w);
    }
    building.printGraph();
    int source, destination;
    fin >> source >> destination;
    PathResult normalResult = PathFinder::findShortestPath(
        building, source, destination
    );
    printPath(building, normalResult, "NORMAL STATE: Lobby -> EXIT");
    cout<<"\n*****Emergency occurred*****\n";
    int n1,n2;
    cout<<"Enter the corridors where fire has broken out\n";
    cin>>n1>>n2;
    building.blockCorridor(n1,n2);   
    building.printGraph();
    PathResult emergencyResult =
        PathFinder::findShortestPath(building, source, destination);
    printPath(building, emergencyResult,
              "EMERGENCY STATE: Lobby -> EXIT (re-routed)");
    cout<<"Normal state "<<normalResult.distance<<endl;
    cout<<"Emergency state "<<emergencyResult.distance;
    fin.close();
}