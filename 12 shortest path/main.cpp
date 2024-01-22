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
#include <set>
using namespace std;

const long long INF = numeric_limits<long long>::max();

struct graph{
    
    int n;
    vector<vector<pair<long long,long long>>> adj;
    
    graph(int n){
        this->n = n;
        this->adj = vector<vector<pair<long long,long long>>> (n);
    }
    
    void addEdge(int u, int v, long long w){
        adj[v].push_back({u,w});//reverse graph
    }
};


long long* dijkstra(struct graph* g, int src, int n, int m){
    long long* dist = new long long[n];
    
    for(int i = 0 ; i < n; i++){
        dist[i] = INF;
    }
    dist[src] = 0;
    
    priority_queue<pair<long long,long long>> pq;
    pq.push({src,0});
    
    while(!pq.empty()){
        
        int u = pq.top().first;
        long long cur_dist = -pq.top().second;
        pq.pop();
        
        if (cur_dist > dist[u]) continue;
        
        for(auto v : g->adj[u]){
            if(cur_dist + v.second < dist[v.first]){
                dist[v.first] = cur_dist + v.second;
                pq.push({v.first, -dist[v.first]});
            }
        }
    }
    
    return dist;
}


int main() {
    string line;
    getline(cin,line);
    stringstream iss(line);
    string word;
    iss>>word;
    long long n = stoi(word);
    iss>>word;
    long long E = stoi(word);
    iss>>word;
    long long B = stoi(word);
    iss>>word;
    long long m = stoi(word);
    
    struct graph* g = new graph(n);
    
    long long idx = 0;
    long long counter = m;
    
    while(counter--){
        getline(cin,line);
        stringstream is(line);
        is>>word;
        int u = stoi(word);
        is>>word;
        int v = stoi(word);
        is>>word;
        long long w = stoi(word);
        // 0 indexing
        if(u != v)
            g->addEdge(u-1,v-1,w);
    }
    
    int count = 0;
    long long* dist = dijkstra(g, E - 1, n, m);

    for(int i = 0 ; i < n ; i++){
        if(dist[i] <= B)
            count++;
    }
    
    cout<<count<<endl;
    
    return 0;
}
