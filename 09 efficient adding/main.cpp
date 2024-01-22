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

long long helper(vector<int>& v);

int main() {
    
    string line;
    getline(cin,line);
    getline(cin,line);
    stringstream iss(line);
    string word;
    vector<int> v;
    
    while(iss>>word){
        v.push_back(stoi(word));
    }
        
    cout<<helper(v)<<endl;
    
    return 0;
}

long long helper(vector<int>& v){
   
    priority_queue<long long, vector<long long>, greater<long long>> pq;

    for (auto num : v) {
        pq.push(num);
    }

    long long ans = 0;
    
    while (pq.size() > 1) {
        
        long long first = pq.top(); 
        pq.pop();
        long long second = pq.top(); 
        pq.pop();
        
        long long cost = first + second;
        ans += cost;

        pq.push(cost);
    }

    return ans;
}
