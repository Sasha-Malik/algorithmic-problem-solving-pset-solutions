
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <cctype>
#include <algorithm>
#include <queue>
//#include <bits/stdc++.h>
using namespace std;

class DisjSet {

public:
    int *rank,*parent,n;

   DisjSet(int n)
   {
       rank = new int[n];
       parent = new int[n];
       this->n = n;
       makeSet();
   }

   void makeSet()
   {
       for (int i = 1; i < n; i++) {
           parent[i] = i;
       }
   }

   int find(int x)
   {
       if (parent[x] != x) {
           parent[x] = find(parent[x]);
       }

       return parent[x];
   }

   void Union(int x, int y)
   {
       int xset = find(x);
       int yset = find(y);

       if (xset == yset)
           return;

       if (rank[xset] < rank[yset]) {
           parent[xset] = yset;
       }
       else if (rank[xset] > rank[yset]) {
           parent[yset] = xset;
       }

       else {
           parent[yset] = xset;
           rank[xset] = rank[xset] + 1;
       }
   }
};

int main() {

    int n , m;
    string line;
    getline(cin,line);
    istringstream iss(line);
    string word;
    iss>>word;
    n = stoi(word);
    iss>>word;
    m = stoi(word);
    
    DisjSet obj(n+1);
    
    int counter = m;
    while(counter > 0){
        getline(cin, line);
        istringstream iss(line);
        string word;
        iss>>word;
        int a = stoi(word);
        iss>>word;
        int b = stoi(word);
        
        obj.Union(a, b);
    
        counter--;
    }
    
    unordered_map<int, int> count;
        
    for (int i = 1; i <= n; i++) {
        int parent = obj.find(i);
        if(count.find(parent) == count.end())
            count[parent] = 1;
        else
            count[parent]++;
    }

           
    int max_f = 0;
    for(auto x : count)
        max_f = max(x.second,max_f);
        
    cout<<max_f<<endl;
    
    return 0;
}
