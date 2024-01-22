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

bool checkDifference(string a, string b){
    int diff = 0;
    for(int i = 0 ; i < a.length() ; i++){
        if(a[i] != b[i])
            diff++;
    }
    
    return diff == 1;
}

int bfs(unordered_map<string, vector<string>> neighbors, string start, string end){
    
    unordered_map<string, int> steps;
    
    queue<string> q;
    q.push(start);
    steps[start] = 0;
    
    while(!q.empty()){
        
        string head = q.front();
        q.pop();
        
        vector<string> cur_neighbors = neighbors[head];
        
        for(auto neighbor : cur_neighbors){
            
            if(neighbor == end)
                return steps[head] + 1;
                
            if(steps.find(neighbor) == steps.end()){
                steps[neighbor] = steps[head] + 1;
            }
            
            q.push(neighbor);
        }
    }
    
    return -1;
}

int main() {
    string line;
    getline(cin,line);
    int n = stoi(line);
    int counter = n;
    
    vector<string> dictionary;

    while(counter--){
        getline(cin, line);
        dictionary.push_back(line);
    }
    
    getline(cin,line);
    int m = stoi(line);
    counter = m;
    vector<pair<string,string>> words;
    while(counter--){
        getline(cin,line);
        stringstream iss(line);
        string word1, word2;
        iss>>word1; iss>>word2;
        words.push_back({word1,word2});
    }
    
    unordered_map<string, vector<string>> neighbors;

    for(int i = 0 ; i < dictionary.size() ; i++){
        for(int j = 0 ; j < dictionary.size() ; j++){
            
            if(i != j && checkDifference(dictionary[i], dictionary[j]))
                neighbors[dictionary[i]].push_back(dictionary[j]);
        }
    }
    
    vector<int> ans;
    
    for(int i = 0 ; i < words.size() ; i++){
        
        string start = words[i].first;
        string end = words[i].second;
        
        if(start == end)
            ans.push_back(0);
        else
            ans.push_back(bfs(neighbors, start, end));
    }
    
    for(auto a : ans)
        cout<<a<<endl;
        
    return 0;
}



