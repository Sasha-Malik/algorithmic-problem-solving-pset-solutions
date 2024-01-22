#include <iostream>
#include <unordered_map>
#include <cstring>
#include <vector>
#include <math.h>
using namespace std;



int dp(vector<int> contestants, int &ans){
    
    if(contestants.size() == 1)
        return ans;
    
    vector<int> c;
    for(int i = 0 ; i < contestants.size() ; i+=2){

        if(contestants[i] != 0 && contestants[i+1] != 0){
            c.push_back(1);
        }

        else if(contestants[i] == 0 && contestants[i+1] == 0){
            c.push_back(0);
        }
        
        else if(contestants[i+1] == 0){
            c.push_back(1);
            ans++;
        }
        
        else if(contestants[i] == 0){
            c.push_back(1);
            ans++;
        }
    }
    
    contestants = c;
    
    return dp(contestants, ans);
}

int main() {
    
//    cout<<"Input : ";
    int n;
    int m;
    cin>>n;
    cin>>m;
    vector<int> walkover;
    int temp = m;
    while( temp > 0){
        int x;
        cin>>x;
        walkover.push_back(x);
        temp--;
    }

    vector<int> contestants;
    for(int i = 1 ; i <= pow(2,n) ; i++)
        contestants.push_back(i);
    
    for(auto x : walkover)
        contestants[x-1] = 0;
    
//    for(auto x : contestants)
//            cout<<x<<" ";
    
    int ans = 0;
    
    cout<<dp(contestants,ans);

    return 0;
}
