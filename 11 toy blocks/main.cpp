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

int helper(vector<vector<vector<int>>>& hash, vector<int>& v, int sum1 , int sum2, int n1, int n2, int n, int idx ){
   
   if(idx > n - 1)
       return abs(sum1 - sum2);
    
   if(hash[idx][n1][sum1] != -1)
       return hash[idx][n1][sum1];
   
   int l = INT_MAX, r = INT_MAX;
    
   if( (n%2 != 0 && n1 <= n / 2) || (n%2 == 0 && n1 < n / 2))
       l = helper(hash, v, sum1 + v[idx], sum2, n1 + 1 , n2, n, idx + 1);
   
    if( (n%2 != 0 && n2 <= n / 2) || (n%2 == 0 && n2 < n / 2))
       r = helper(hash, v, sum1, sum2 + v[idx], n1, n2 + 1, n, idx + 1);
   
    hash[idx][n1][sum1] = min(l,r);
    return hash[idx][n1][sum1];
}

int main() {
   string line;
   getline(cin,line);
   int n = stoi(line);
   int counter = n;
   
   vector<int> v;
   int sum = 0;

   while(counter--){
       getline(cin, line);
       v.push_back(stoi(line));
       sum += stoi(line);
   }
    
   vector<vector<vector<int>>> hash(n , vector<vector<int>> (n, vector<int>(sum, -1)));
   
   int diff = helper(hash, v, 0, 0, 0, 0, n, 0);
   
   //ans2 + ans1 = sum
   //ans2 - ans1 = diff
   
   int ans2 = (sum + diff)/2;
   int ans1 = sum - ans2;
   
   cout<<ans1<<" "<<ans2<<endl;

   return 0;
}
