#include <iostream>
#include <climits>

using namespace std;

#define V 6

int minmumKey(int key[] , bool mst[]){
    int min = INT_MAX ;
    int min_index;
    for(int v = 0  ; v < V ; v++){
        if(mst[v] == false && key[v] < min ){
            min = key[v];
            min_index = v;
        }
    }
    return min_index;
}

void printMST(int parent[], int graph[V][V])
{
    
    for (int i = 1; i < V; i++)
        cout << parent[i] << " - " << i << " \t"<< graph[i][parent[i]] << " \n";
}
void prims(int graph[V][V]){

    int parent[V];
    int key[V];

    bool mst[V];

    for(int i = 0 ; i < V ; i++){
        key[i] = INT_MAX;
        mst[i] = false;

    }

    key[0] = 0;

    parent[0] = -1;

    for(int count = 0 ; count < V-1 ; count++){
        int u = minmumKey(key, mst);

        mst[u] = true;

        for(int v = 0 ; v < V ; v++){
            if (graph[u][v] && mst[v] == false && graph[u][v] < key[v]){
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }

    }

    printMST(parent, graph);
}



int main()
{
    int graph[V][V] = { { 0, 3, 0, 0, 0, 1 },
                        { 3, 0, 2, 1, 10, 0 },
                        { 0, 2, 0, 3, 0, 5 },
                        { 0, 1, 3, 0, 5, 0 },
                        { 0, 10, 0, 5, 0, 4 },
                        { 1, 0, 5, 0, 4, 0 } };
 
    
    prims(graph);
 
    return 0;
}