
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <cctype>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;

int main() {

    int n , m;
    string line;
    getline(cin,line);
    istringstream iss(line);
    string word;
    iss>>word;
    n = stoi(word);
    
    stack<int> s;
    queue<int> q;
    priority_queue<int> pq;
    
    vector<int> output;
    vector<int> out_s;
    vector<int> out_q;
    vector<int> out_pq;
    
    int flag_s = 1, flag_q = 1, flag_pq = 1;
    
    int counter = n;
    while(counter > 0){
        getline(cin, line);
        istringstream iss(line);
        string word;
        iss>>word;
        int a = stoi(word);
        iss>>word;
        int b = stoi(word);
        
        if(a == 1){
            s.push(b);
            q.push(b);
            pq.push(b);
        }
        
        else{
            output.push_back(b);
            
            if (!s.empty()) {
                out_s.push_back(s.top());
                s.pop();
            }
            else flag_s = 0;
                        
            if (!q.empty()) {
                out_q.push_back(q.front());
                q.pop();
            }
            else flag_q = 0;
            
            if (!pq.empty()) {
                out_pq.push_back(pq.top());
                pq.pop();
            }
            else flag_pq = 0;
             
        }
        
        counter--;
    }
    
    
    for(int i = 0 ; i < output.size(); i++){
        
        if(flag_s && output[i] != out_s[i])
            flag_s = 0;
        
        if( flag_q && output[i] != out_q[i])
            flag_q = 0;
        
        if( flag_pq && output[i] != out_pq[i])
            flag_pq = 0;
    }
    
    
    if(!flag_q && !flag_s && !flag_pq )
        cout<<"impossible"<<endl;
    else if( (flag_q && flag_s) || (flag_s && flag_pq) || (flag_pq && flag_q))
        cout<<"not sure"<<endl;
    else if(flag_s)
        cout<<"stack"<<endl;
    else if(flag_q)
        cout<<"queue"<<endl;
    else if(flag_pq)
        cout<<"priority queue"<<endl;
  
    return 0;
}
