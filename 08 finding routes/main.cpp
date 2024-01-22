
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

void dfs(vector<vector<int>>& ans, unordered_map<int, vector<int>>& map, unordered_map<int,int>& vis, vector<int> route, int cur, int& target);

int main() {
    
    string line;
    getline(cin,line);
    stringstream iss(line);
    string word;
    iss>>word;
    int target = stoi(word);
    
    unordered_map<int, vector<int>> map;
    
    while(true){
        getline(cin,line);
        if(line == "0 0")
            break;
        
        stringstream is(line);
        is>>word;
        int a = stoi(word);
        is>>word;
        int b = stoi(word);

        map[a].push_back(b);
        map[b].push_back(a);
    }
    
    
    for(auto v : map){
        vector<int> temp = v.second;
        sort(temp.begin(),temp.end());
        map[v.first] = temp;
    }
        
    vector<vector<int>> ans;
    unordered_map<int,int> vis;


    dfs(ans, map , vis, vector<int>(), 1, target);
    
    for(auto line : ans){
        int len = line.size();
        for(int i = 0 ; i < len ; i++){
            if(i != len - 1 )
                cout<<line[i]<<" ";
            else
                cout<<line[i];
        }
            
        cout<<endl;
    }
    cout<<"There are "<<ans.size()<<" routes from the initial position to corner "<<target<<".";
    
    return 0;
}

void dfs(vector<vector<int>>& ans, unordered_map<int, vector<int>>& map, unordered_map<int,int>& vis, vector<int> route, int cur, int& target){
    
    route.push_back(cur);
    vis[cur] = 1;
    
    if(cur == target){
        ans.push_back(route);
        return;
    }
    
    for(auto x : map[cur]){
        
        if(vis[x] != 1){
            dfs(ans,map, vis, route, x, target);
            vis[x] = 0;
        }
           
        
    }
}


/*
Input:
6
1 2
1 3
3 4
3 5
4 6
5 6
2 3
2 4
0 0
 
 Output:
 1 2 3 4 6
 1 2 3 5 6
 1 2 4 3 5 6
 1 2 4 6
 1 3 2 4 6
 1 3 4 6
 1 3 5 6

 Input:
4
2 3
3 4
5 1
1 6
7 8
8 9
2 5
5 7
3 1
1 8
4 6
6 9
0 0
 
 Output:
 1 3 2 5 7 8 9 6 4
 1 3 4
 1 5 2 3 4
 1 5 7 8 9 6 4
 1 6 4
 1 6 9 8 7 5 2 3 4
 1 8 7 5 2 3 4
 1 8 9 6 4
 */
