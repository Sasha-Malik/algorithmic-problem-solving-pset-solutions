#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
#include <fstream>
#include <sstream>
#include <queue>
#include <algorithm>

using namespace std;

void helper(vector<string>& ans, vector<char>& combine, stack<char>& s, string& cur , int pos_in, int pos_out , int n, string& in, string& out){
    
    if(pos_in > n )
        return;
    
    if(combine.size() == 2*n){
        string temp = "";
        for(auto x : combine)
            temp = temp + x;
        ans.push_back(temp);
        return;
    }
    
    // 2 choices to take i or o
    
    //push i
    s.push(in[pos_in]);
    combine.push_back('i');
    helper(ans, combine, s, cur, pos_in + 1, pos_out, n, in, out);
    combine.pop_back();
    s.pop();
    
    //push o
    if(s.empty())
        return;
    
    // doesn't match the output string
    if(s.top() != out[pos_out]){
        return;
    }
    
    char top = s.top();
    s.pop();
    
    cur = cur + top; //update cur string
   
    combine.push_back('o');
    helper(ans, combine, s , cur , pos_in, pos_out + 1 , n, in, out);
    
    s.push(top);
    combine.pop_back();
    cur.pop_back();
}

int main(){
    string line;
//    ifstream inputFile("input.txt");
    string in;
    string out;
    unordered_map<int, int> freq;
  
    getline(cin, line);
    in = line;
    getline(cin, line);
    out = line;
//    inputFile.close();
    
    vector<char> combine;
    stack<char> s;
    vector<string> ans;
    
    string cur="";
    helper(ans, combine, s, cur, 0, 0, in.length(), in , out);
    sort(ans.begin() , ans.end());
    
    cout<<"["<<endl;
    for(auto a : ans){
        for(int i = 0 ; i < a.length() ; i++){
            if(i!= a.length()-1)
                cout<<a[i]<<" ";
            else
                cout<<a[i];
        }
           
        cout<<endl;
    }
    cout<<"]"<<endl;
            
    return 0;
}

