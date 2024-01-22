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

int dp(vector<vector<int>>& hash, string& s1 , string& s2, int idx1, int idx2, int n1, int n2){
    
    if(idx1 > n1 - 1 || idx2 > n2 - 1){
        return 0;
    }
    
    if(hash[idx1][idx2] != -1)
        return hash[idx1][idx2];
    
    int c1 = 0, c2 = 0, c3 = 0;
    
    if(s1[idx1] == s2[idx2]){
        hash[idx1][idx2] = dp(hash, s1, s2, idx1 + 1, idx2 + 1, n1, n2) + 1;
        return hash[idx1][idx2];
    }
     
    else{
        c2 = dp(hash, s1, s2, idx1 + 1, idx2, n1, n2);
        c3 = dp(hash, s1, s2, idx1, idx2 + 1, n1, n2);
        
        hash[idx1][idx2] = max(c2,c3);
        return max(c2, c3);
    }
}


int main() {
    string line;
    
    while(true){

        if(!getline(cin, line))
            break;
        string s1 = line;
        
        if(!getline(cin, line))
            break;
        string s2 = line;
        
        int n1 = s1.length(), n2 = s2.length();
        
        vector<vector<int>> hash (n1, vector<int>(n2, -1));
        cout<<dp(hash, s1, s2, 0, 0, n1, n2)<<endl;
    }

    return 0;
}



