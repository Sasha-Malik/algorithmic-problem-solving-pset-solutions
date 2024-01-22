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
#include <cmath>
using namespace std;

int main() {
        
    string line;
    getline(cin,line);
    stringstream iss(line);
    string word;
    iss>>word;
    int n = stoi(word);
    iss>>word;
    int l = stoi(word);
    iss>>word;
    int w = stoi(word);

    vector<pair<double,double>> v;
    
    int counter = n;
        
    while(counter > 0){
        getline(cin,line);
        stringstream is(line);
        is>>word;
        int x = stoi(word);
        is>>word;
        double r = stof(word);
        
        // covered area from x - y -> x + y
        // y = sqrt(r * r - w * w / 4.0);
        double start,end;
        if(r <= w/2){
            start = x;
            end = x;
        }
        
        else{
            double y =  max(0.0, sqrt(r * r - w * w / 4.0));
            start = max(0.0, x - y);
            end = min((double)l , x + y);
        }

        v.push_back({start, end});
        counter--;
    }
    
    sort(v.begin(),v.end(),[](pair<double,double> a, pair<double,double> b){
//        if (a.first == b.first)
//            return a.second > b.second;
        return a.first < b.first;
    });
    
//    for(auto p : v)
//        cout<<p.first<<" : "<<p.second<<endl;
    
    int count = 0;
    bool flag = false;
    double maxRight = 0, nextRight = 0;
    
    for (int i = 0; i < n && maxRight < l; ) {
        
            bool updated = false;
        
            //check which sprinkler covers the max area, compare till the end of cur
            while (i < n && v[i].first <= maxRight) {  //make sure new sprinkler->start <= cur->end
                nextRight = max(nextRight, v[i].second);
                updated = true;
                i++;
            }
            if (!updated) break;
            maxRight = nextRight;
            count++;
    }
    
    if(maxRight >= l)
        cout<<(count == 0 ? -1 : count)<<endl;
    else
        cout<<-1<<endl;

    return 0;
}
