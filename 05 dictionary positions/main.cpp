
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <cctype>
#include <algorithm>

using namespace std;


void backtrack(vector<char>& combine, vector<char>& candidates , int pos, vector<string>& ans){
    
    string temp  = "";
    for(auto x : combine)
        temp = temp + x;
    ans.push_back(temp);
    
    
    if(combine.size() == 6)
        return;
    
    for(int i = pos; i < candidates.size() ; i++){
        combine.push_back(candidates[i]);
        backtrack(combine,candidates, i + 1, ans);
        combine.pop_back();
    }
    
}

int main() {
//    cout<<"input :";
    string line;
    getline(cin, line);
    vector<char> combine;
    vector<char> candidates;
    for(char i = 'a' ; i <= 'z' ; i++)
        candidates.push_back(i);

    vector<string> ans;
    backtrack(combine, candidates, 0, ans);
    

    sort(ans.begin(),ans.end(), []
         (const string& first, const string& second){
            
             if(first.size() == second.size()){
                 return first< second;
             }
        
            else
                 return first.size() < second.size();
         });
    
    unordered_map<string, int> map;
    int count = 0;
    for(auto a : ans){
        map[a] = count;
        count++;
    }
       
    if(map.find(line) == map.end())
        cout<<0;
    else
        cout<<map[line];

    return 0;
}
