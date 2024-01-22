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
    int n = stoi(line);

    vector<int> v;
    
    int counter = n - 1;
    
    while(counter > 0){
        getline(cin,line);
        v.push_back(stoi(line));
        counter--;
    }
    
    long long curSum = LONG_MIN;
    long long gloabalSum = LONG_MIN;
    int start = 0;
    int end = 0;
    
    int globalStart = 0;
    int globalEnd = 0;
    
    for(int i = 0 ; i < n - 1 ; i++){
        
        // same as v[i] > curSum + v[i]
        if(0 > curSum){
            curSum = v[i];
            start = i;
            end = i;
        }
        
        else{
            curSum += v[i];
            end = i;
        }
           
        
        if(curSum > gloabalSum){
            globalStart = start;
            globalEnd = end;
            gloabalSum = curSum;
        }
    
        else if(gloabalSum == curSum){
            if(globalEnd - globalStart < end - start){
                globalStart = start;
                globalEnd = end;
            }
            
            else if(globalEnd - globalStart == end - start){
                if(start < globalStart){
                    globalStart = start;
                    globalEnd = end;
                }
            }
        }
    }
    
    if(gloabalSum < 0)
        cout<<"Yet another overrated tourist destination"<<endl;
    
    else
        cout<<"The nicest part of Y1 is between stops "<<globalStart + 1 <<" and "<<globalEnd + 2<<endl;
    
//    cout<<gloabalSum;

    return 0;
}
