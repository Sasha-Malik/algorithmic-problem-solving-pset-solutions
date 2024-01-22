
#include <iostream>
#include <unordered_map>
#include <cstring>
#include <vector>
#include <math.h>
#include <sstream>
#include <algorithm>
#include <stack>
using namespace std;

bool match(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '[' && close == ']') ||
           (open == '{' && close == '}');
}


int main() {
    string s;
    getline(cin, s);
    stack<pair<char,int>> st1;
    
    for(int i = 0 ; i < s.length() ; i++){
        if(  s[i] == ')'  || s[i] == ']'  || s[i] == '}'){
            
            if( !st1.empty() && match(st1.top().first , s[i]) )
                st1.pop();
            
            else if(st1.empty() || !match(st1.top().first , s[i])){
                cout<<"NO "<<i + 1<<endl;
                return 0;
            }
        }
        
        else if (s[i] == '(' || s[i] == '[' || s[i] == '{'){
            st1.push({s[i],i});
        }
    }
        
    if(st1.empty())
        cout<<"YES"<<endl;
    else
        cout<<"NO "<<s.length()+1<<endl;

    return 0;
}
