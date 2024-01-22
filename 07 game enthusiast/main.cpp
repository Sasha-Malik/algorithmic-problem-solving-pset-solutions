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


int dp(vector<vector<int>>& hash, vector<int>& v , int& w, int sum, int idx, int& len){
        
    if(idx > len - 1)
        return sum;
    
    if(hash[idx][sum] != -1)
        return hash[idx][sum];
    
    //take
    int l = 0;
    if(sum + v[idx] <= w)
        l = dp(hash, v , w, sum + v[idx], idx + 1, len);
    
    //skip
    int r = dp(hash, v , w, sum, idx + 1, len);
    
    return max(l,r);
}

int main() {

    string line;
    getline(cin,line);
    stringstream iss(line);
    string word;
    
    iss>>word;
    int w = stoi(word);
    iss>>word;
    int len = stoi(word);
    
    if(len == 0){
        cout<<w<<endl;
        return 0;
    }
    
    getline(cin,line);
    stringstream is(line);
    
    vector<int> v;
    
    while( is>>word ){
        v.push_back(stoi(word));
    }
    
    vector<vector<int>> hash(20, vector<int>(10000,-1));
    
    cout<<dp(hash, v, w, 0, 0, len)<<endl;
    
    return 0;
}
