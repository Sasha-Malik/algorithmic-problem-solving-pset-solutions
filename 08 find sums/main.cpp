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
using namespace std;


void dp( vector<string>& ans, unordered_map<string, int>& map, vector<int>& nums , string combine, int target, int idx, int n){
    
    if(target == 0){
        
        if(map.find(combine) == map.end()){
            ans.push_back(combine);
            map[combine] = 1;
        }
            
        return;
    }
    
    if(idx == n)
        return;
    
    //two choices
    
    //take
    if(target - nums[idx] >= 0){
        dp(ans, map, nums, combine + to_string(nums[idx]) + "+", target - nums[idx], idx + 1, n);
    }
    
    //skip
    dp(ans, map, nums, combine, target, idx + 1, n);
    
}


int main() {
    
    string line;
    getline(cin,line);
    stringstream iss(line);
    string word;
    iss>>word;
    int target = stoi(word);
    iss>>word;
    int n = stoi(word);
    
    getline(cin,line);
    stringstream is(line);
    vector<int> nums;
    while(is>>word){
        nums.push_back(stoi(word));
    }
    
    sort(nums.begin(), nums.end(), [](int a, int b){ return a > b; } );
    
    vector<string> ans;
    unordered_map<string, int> map;
    
    dp(ans, map, nums, "", target, 0 , n);
    
    cout<<"Sums of " + to_string(target)<<":"<<endl;
    
    if(ans.size() == 0)
        cout<<"NONE"<<endl;
        
    else
        for(auto line : ans){
            line.pop_back();
            cout<<line<<endl;
        }
      
    return 0;
}

// no credits
