#include <iostream>
#include <climits>
using namespace std;

#define V 6 // Number of vertices in the graph

int findMinDistanceVertex(int distance[], bool shortestPathTree[])
{
    int minDist = INT_MAX; //  min value taken as infinity
    int minVertex; //  index of min value

    for (int y = 0; y < V; y++) {
    if (!shortestPathTree[y] && distance[y] <= minDist) { //  if vertex y is not in shortestPathTree and distance[y] is less than minDist
        minDist = distance[y]; // update minDist
        minVertex = y;
    }
}

    return minVertex;
}



void print(int distance[] , int sourceNode)
{   
    cout << "Source Node: " << sourceNode << endl;

    for (int i = 0; i < V; i++){
        
        if (i != sourceNode){
            cout <<"Shortest Time of node " << i << ":    " << distance[i] << endl;
        }
        
    }
}

void getAverage(int distance[]){
    float sum = 0;
    for (int i = 0; i < V; i++){
        sum += distance[i];
    }
    float   average = sum/(V-1);
    cout << "Average Time: " << average << endl; //  V-1 because we don't want to include the source node

}





void dijkstra(int graph[V][V], int sourceNode)
{
    int distance[V]; //  distance[i] will hold the shortest distance from sourceNode to i
    bool shortestPathTree[V];  //  shortestPathTree[i] will be true if vertex i is included in shortestPathTree
    for (int i = 0; i < V; i++) {
        distance[i] = INT_MAX; // get all distances as INFINITE and shortestPathTree[] as false
        shortestPathTree[i] = false;
    }
    distance[sourceNode] = 0; //  distance from sourceNode to itself is 0
    for (int count = 0; count < V - 1; count++)
    {
        int x = findMinDistanceVertex(distance, shortestPathTree); //  pick the minimum distance
        shortestPathTree[x] = true; //  mark the picked vertex as processed
        for (int y = 0; y < V; y++) {
            // check if vertex y is not in shortestPathTree and there is an edge from x to y and total weight of path from sourceNode to y through x is smaller than current value of distance[y]
            if (!shortestPathTree[y] && graph[x][y] && distance[x] != INT_MAX && distance[x] + graph[x][y] < distance[y]) { 
                distance[y] = distance[x] + graph[x][y]; //  update distance value
            }
        }

    
    }
    print(distance , sourceNode); 
    getAverage(distance); //  get average time

}

int main()
{

    int graph[V][V] = {{0, 10, 0, 0, 15, 5},         
                       {10, 0, 10, 30, 0, 0},
                       {0, 10, 0, 12, 5, 0},
                       {0, 30, 12, 0, 0, 20},
                       {15, 0, 5, 0, 0, 0},
                       {5, 0, 0, 20, 0, 0}
                       };

    dijkstra(graph, 5);
    

    return 0;
}



