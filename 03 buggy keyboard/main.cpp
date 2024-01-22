
#include <iostream>
#include <unordered_map>
#include <cstring>
#include <vector>
#include <math.h>
#include <sstream>
#include <algorithm>
#include <stack>
using namespace std;


int main() {

//    cout<<"Input : ";
    
    string input;
    getline(cin,input);
    
    int n  = input.length();
    stack<char> s;
    
    for(int i = 0 ; i < n ; i++){
        if(input[i] != '<')
            s.push(input[i]);
        
        else{
            s.pop();
        }
    }
    
    string ans;
    while(!s.empty()){
        ans+=s.top();
        s.pop();
    }
        
    reverse(ans.begin(), ans.end());
    cout<<ans;

    return 0;
}
