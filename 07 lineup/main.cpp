#include <iostream>
#include <unordered_map>
#include <cstring>
#include <vector>
#include <math.h>
#include <sstream>
#include <algorithm>
#include <stack>
#include <queue>
#include <limits.h>
#include <iterator>
using namespace std;


int main() {
    int n;
    string line;
    getline(cin,line);
    n = stoi(line);
    
    unordered_map<int,int> map;

    vector<queue<int>> q(n);
    queue<int> group_order;
    
    vector<int> ans;
    
    
    int count = n;
    int group = 0;// group index
    
    while(count > 0){
        getline(cin,line);
        istringstream iss(line);
        string word;
        iss>>word;
        while(iss>>word){
            map[stoi(word)] = group; // group indices
        }
        
        count--;
        group++;
    }
    
    while(true){
        getline(cin,line);
        
        if(line == "Shutdown")
            break;
        
        if( line == "Pop" ){
            
            int group = group_order.front();
            int element = q[group].front();
            q[group].pop();
            
            if (q[group].empty())
                group_order.pop();
            
            ans.push_back(element);
        }
        
        //Push operation
        else{
            
            stringstream iss(line);
            string word;
            iss>>word;
            iss>>word;
            
            int element = stoi(word) ;
            int group = map[element];
            q[group].push(element);
            if (q[group].size() == 1)
                group_order.push(group);
                          
        }
        
    }//while
    
    for(auto a : ans) cout<<a<<endl;
  
    return 0;
}
