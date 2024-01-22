#include <iostream>
#include <unordered_map>
#include <cstring>
#include <vector>
#include <math.h>
#include <sstream>
#include <algorithm>
using namespace std;

vector<vector<int>> ans;

vector<int> convertToSingleNumbers(const vector<vector<int>>& ans) {
    vector<int> result;
    
    for (const vector<int>& innerVector : ans) {
        int concatenated = 0;
        for (int num : innerVector) {
            concatenated = concatenated * 10 + num;
        }
        
        result.push_back(concatenated);
    }
    return result;
}


void helper(vector<int>& candidates, vector<int>& combine){
    
    ans.push_back(combine);
    
    if (combine.size() >= 7)
        return;
    
    for(int i = 0 ; i < candidates.size() ; i++){
        combine.push_back(candidates[i]);
        helper(candidates, combine);
        combine.pop_back();
    }
}


int main() {

    vector<int> candidates;
    candidates.push_back(4);
    candidates.push_back(7);
    vector<int> combine;
    helper(candidates, combine);
   
    vector<int> converted = convertToSingleNumbers(ans);
    sort(converted.begin() , converted.end());

    int n;
    cin>>n;
    
    for(auto x : converted){
        if(x == 0)
            continue;
        
        if(x > n){
            cout<<"Not in the family"<<endl;
            return 0;
        }
        if(n%x == 0){
            cout<<"July Fourth Family Number"<<endl;
            return 0;
        }
    }
        
    return 0;
}
