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
//
//int helper(vector<vector<int>>& dp, vector<int>& v, int capacity, int n, int sum, int idx){
//
//    if(idx > n - 1)
//        return 0;
//
//    if(dp[idx][sum] != -1)
//        return dp[idx][sum];
//
//    int take = 0, skip = 0;
//
//    if(sum + v[idx] <= capacity)
//        take = helper(dp, v, capacity, n, sum + v[idx], idx + 1) + 1;
//
//    skip = helper(dp, v, capacity , n, sum, idx + 1);
//
//
//    dp[idx][sum] = max(take,skip);
//    return max(take,skip);
//}


int helper(int capacity, vector<int>& v) {

    sort(v.begin(), v.end());

    int count = 0;
    int currentWeight = 0;

    // Iterate through the v and add as many as possible
    for (int weight : v) {
        if (currentWeight + weight <= capacity) {
            currentWeight += weight;
            count++;
        } else {
            // Break the loop if adding another hippo exceeds the weight limit
            break;
        }
    }

    return count;
}

int main() {
    string line;
    getline(cin,line);
    int capacity = stoi(line);
    getline(cin,line);
    int n = stoi(line);
    getline(cin, line);
    string word;
    stringstream iss(line);
    vector<int> v;

    while(iss>>word){
        v.push_back(stoi(word));
    }

//    cout<<helper(dp, v, capacity, n , 0, 0);
    cout<<helper(capacity, v);
    return 0;
}



