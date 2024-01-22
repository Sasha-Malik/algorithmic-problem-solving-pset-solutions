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

int dp(vector<vector<int>>& hash, string x, string& y, int len_x, int& len_y, int idx1, int idx2){
    
    if(idx1 > len_x - 1)
        return len_y - idx2;
    
    if(idx2 > len_y - 1)
        return len_x - idx1;
    
    if(hash[idx1][idx2] != -1)
        return hash[idx1][idx2];
    
    if(x[idx1] == y[idx2]){
        hash[idx1][idx2] = dp(hash, x, y, len_x, len_y, idx1 + 1, idx2 + 1);
        return hash[idx1][idx2];
    }
        
    int c1 = dp(hash, x, y, len_x, len_y, idx1 + 1, idx2);
    int c2 = dp(hash, x, y, len_x, len_y, idx1, idx2 + 1);
    int c3 = dp(hash, x, y, len_x, len_y, idx1 + 1, idx2 + 1);
    
    hash[idx1][idx2] = min(min(c1,c2),c3) + 1;
    
    return hash[idx1][idx2];
}

int main() {
    
    string line;
    string word;
    
    getline(cin,line);
    stringstream iss(line);
    iss>>word;
    int len_x = stoi(word);
    iss>>word;
    string x = word;
    
    getline(cin,line);
    stringstream is(line);
    is>>word;
    int len_y = stoi(word);
    is>>word;
    string y = word;
    
    vector<vector<int>> hash(len_x, vector<int>(len_y, -1));
    
    cout<<dp(hash, x, y, len_x, len_y, 0, 0)<<endl;

    return 0;
}



