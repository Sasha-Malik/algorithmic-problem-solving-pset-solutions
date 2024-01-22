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

void bfs(vector<vector<bool>>& grid, vector<vector<bool>>& water, int r, int c, int m, int n){
    
    vector<pair<int,int>> dir = { {m, n}, {-m, -n},{m,-n},{-m,n} , {n,m}, {-n,-m}, {n,-m}, {-n,m} };
    
    pair<int,int> head;
    queue<pair<int,int>> q;
    q.push({1,1});
    grid[1][1] = true;
    
    while(!q.empty()){
        
        head = q.front();
        
        q.pop();
        
        for(auto d : dir){
            
            int x = head.first + d.first, y = head.second + d.second;
            
            if(x <= r && x > 0 && y <= c && y > 0){
                
                if(!water[x][y] && !grid[x][y]){
                    q.push({x,y});
                    grid[x][y] = true;
                }
            }
            
        }
    }
    
}

int main() {
    string line;
    getline(cin,line);
    stringstream iss(line);
    string word;
    iss>>word;
    int r = stoi(word);
    iss>>word;
    int c = stoi(word);
    iss>>word;
    int m = stoi(word);
    iss>>word;
    int n = stoi(word);
    
    getline(cin,line);
    int w = stoi(line);
    int counter = w;
   
    vector<vector<bool>> grid (r + 1, vector<bool>(c + 1, false));
    vector<vector<bool>> water(r + 1, vector<bool>(c + 1, false));

    while(counter > 0){
        getline(cin, line);
        stringstream is(line);
        is>>word;
        int x = stoi(word);
        is>>word;
        int y = stoi(word);
        water[x][y] = true;
        counter--;
    }
    
    bfs(grid, water, r, c, m, n);
    vector<pair<int,int>> dir = { {m, n}, {-m, -n}, {m,-n}, {-m,n} ,{n,m},{-n,-m}, {n,-m}, {-n,m} };
    int even = 0;
    int odd = 0;
    
    for(int i = 1 ; i <= r ; i++){
        for(int j = 1 ; j <= c ; j++){
            
            if(grid[i][j]){
                
                int count = 0;
                unordered_map<string, int> map;
                
                for(auto d : dir){
                    
                    int x = i + d.first, y = j + d.second;
                    
                    string pos_str = to_string(x) + to_string(y);
                    
                    if(x <= r && x > 0 && y <= c && y > 0 && !water[x][y] && map.find(pos_str) == map.end()){
                        count++;
                        map[pos_str] = 1;
                    }
                        
                }
                
                if(count%2 == 0)
                    even++;
                else
                    odd++;
                
            }
        }
    }
    
    cout<<even<<" "<<odd<<endl;
   
   return 0;
}
