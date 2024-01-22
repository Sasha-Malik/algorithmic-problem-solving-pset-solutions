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
using namespace std;

// Credits : C++ implementation of disjoint set from Geeks for Geeks
class DisjSet {
    vector<int> rank, parent, size;
public:
    DisjSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

bool isValid(int adjr, int adjc, int n, int m) {
    return adjr >= 0 && adjr < n && adjc >= 0 && adjc < m;
}


int main() {

    int n,m;
    string line;
    getline(cin,line);
    istringstream iss(line);
    string word;
    iss>>word;
    n = stoi(word);
    iss>>word;
    m = stoi(word);
    
    vector<vector<int>> mat;
    vector<pair<int, pair<int, int>> > positions;
    
    int count = n;
    while(count > 0){
        
        getline(cin,line);
        istringstream iss(line);
        string word;
        vector<int> v;
                
        while(iss>>word){
            v.push_back(stol(word));
        }
        mat.push_back(v);
      
        count--;
    }
    
    for(int i = 0 ; i < n ; i ++){
        for(int j = 0 ; j < m ; j++){
            positions.push_back({mat[i][j], {i, j}});
        }
    }
    
    getline(cin, line);
    int num_levels = stoi(line);
    getline(cin,line);
    istringstream iss2(line);
    vector<int> levels;
    while(iss2>>word){
        levels.push_back(stoi(word));
    }
    
    vector<int> ans;
    
    //descending order
    sort(positions.begin(), positions.end(), [](pair<int,pair<int,int>> a, pair<int,pair<int,int>> b){return a.first > b.first;});
    
    //descending order of levels
    reverse(levels.begin(),levels.end());
    
    DisjSet dsu(n * m);
    
    int currentPos = 0;
    int cnt = 0; //no islands initially

    for(auto level : levels){
        
        while (positions[currentPos].first > level) {
            
            //new island due to first time visit
            cnt++;
            
            int row = positions[currentPos].second.first;
            int col = positions[currentPos].second.second;
            
            int dr[] = { -1, 0, 1, 0};
            int dc[] = {0, 1, 0, -1};
            
            //takes care of adjacent nodes and reduces number of islands
            for (int ind = 0; ind < 4; ind++) {
                
                int adjr = row + dr[ind];
                int adjc = col + dc[ind];
                
                if (isValid(adjr, adjc, n, m)) {
                    
                    //if the ajacent cells are already existing land cells
                    if (mat[adjr][adjc] > level) {
                        
                        int nodeNo = row * m + col;
                        int adjNodeNo = adjr * m + adjc;
                        
                        //reduce num of islands if the new cell connects two islands
                        if (dsu.findUPar(nodeNo) != dsu.findUPar(adjNodeNo)) {
                            cnt--;
                            dsu.unionBySize(nodeNo, adjNodeNo);
                        }
                    }
                }
            }

            currentPos++;
        }
        
        ans.push_back(cnt);
    }

    
    for(int i = num_levels -1; i >= 0; i--){
        if(i == 0){
            cout<<ans[i]<<endl;
        }
        else
            cout<<ans[i]<<" ";
    }
    
    return 0;
}

// credits : (approach for reducing islands based on existing islands) -> lc num of islands II
