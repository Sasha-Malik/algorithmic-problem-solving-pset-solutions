#include <iostream>
#include <unordered_map>
#include <cstring>
#include <vector>
#include <math.h>
#include <sstream>
#include <algorithm>
#include <stack>
#include <limits.h>
#include <queue>
#include <fstream>
#include <bitset>
using namespace std;

struct Edge {
    int src, dest, weight;
};
 
struct Graph {
   
    int V, E;
    struct Edge* edge;
};
 

struct Graph* createGraph(int V, int E)
{
    struct Graph* graph = new Graph;
    graph->V = V;
    graph->E = E;
    graph->edge = new Edge[graph->E];
    return graph;
}
 
bool isNegCycleBellmanFord(struct Graph* graph, int src,
                           int dist[])
{
    int V = graph->V;
    int E = graph->E;
 
    for (int i = 0; i < V; i++)
        dist[i] = 1001;
    dist[src] = 0;
 
    for (int i = 1; i <= V - 1; i++) {
        for (int j = 0; j < E; j++) {
            int u = graph->edge[j].src;
            int v = graph->edge[j].dest;
            int weight = graph->edge[j].weight;
            if (dist[u] != 1001
                && dist[u] + weight < dist[v])
                dist[v] = dist[u] + weight;
        }
    }
 

    for (int i = 0; i < E; i++) {
        int u = graph->edge[i].src;
        int v = graph->edge[i].dest;
        int weight = graph->edge[i].weight;
        if (dist[u] != 1001
            && dist[u] + weight < dist[v])
            return true;
    }
 
    return false;
}

bool isNegCycleDisconnected(struct Graph* graph)
{
 
    int V = graph->V;
 
    bool visited[V];
    memset(visited, 0, sizeof(visited));
 
    int dist[V];

    for (int i = 0; i < V; i++) {
        if (visited[i] == false) {

            if (isNegCycleBellmanFord(graph, i, dist))
                return true;
 
            for (int i = 0; i < V; i++)
                if (dist[i] != 1001)
                    visited[i] = true;
        }
    }
 
    return false;
}


int main() {
    string line;
    getline(cin,line);
    stringstream iss(line);
    string word;
    iss>>word;
    int n = stoi(word);
    iss>>word;
    int m = stoi(word);
    int counter = m;
    
    struct Graph* graph = createGraph(n, m);
    
    int idx = 0;
    
    while(counter--){
        getline(cin, line);
        stringstream is(line);
        is>>word;
        int x = stoi(word);
        is>>word;
        int y = stoi(word);
        is>>word;
        int w = stoi(word);
        
        graph->edge[idx].src = x;
        graph->edge[idx].dest = y;
        graph->edge[idx].weight = w;
        idx++;
    }
    
    if(isNegCycleDisconnected(graph))
        cout <<"possible"<<endl;
    else
        cout <<"not possible"<<endl;
   
   return 0;
//cred : gfg implementation of "Detect a negative cycle in a Graph | (Bellman Ford)"
}
