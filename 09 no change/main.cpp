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

long dp(vector<vector<int>>& map, unordered_map<int, int>& freq, vector<int>& v , int idx, long sum , int target, int n, int count);

int main() {
    
    string line;
    getline(cin,line);
    int target = stoi(line);
    getline(cin,line);
    int n = stoi(line);

    vector<int> v;
    
    while(n > 0){
        getline(cin,line);
        v.push_back(stoi(line));
        n--;
    }
    
    n = v.size();

    unordered_map<int, int> freq;
    vector<vector<int>> map (target + 1, vector<int>(n + 1, -1));

    int ans = dp(map, freq, v, 0, 0, target, n, 0);
    cout<<ans<<" "<<freq[ans]<<endl;
    return 0;
}

long dp(vector<vector<int>>& map, unordered_map<int, int>& freq, vector<int>& v , int idx, long sum , int target, int n, int count){
    
    if(sum >= target){
        
        if(freq.find(sum) == freq.end())
            freq[sum] = count;
        else
            freq[sum] = min(freq[sum], count);
        
        return 0;
    }
        
    
    if(idx >= n)
        return INT_MAX;
    
    if(map[sum][count] != -1)
        return map[sum][count];
    
    // skip
    long skip = dp(map, freq, v, idx + 1, sum, target, n, count);
    
    //take
    long take = dp(map, freq, v, idx + 1, sum + v[idx], target, n, count + 1) + v[idx];
    
    int ans = min(skip, take);
    map[sum][count] = ans;

    return ans;
}
