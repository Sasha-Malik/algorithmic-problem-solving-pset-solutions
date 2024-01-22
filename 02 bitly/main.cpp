#include <iostream>
#include <unordered_map>
#include <cstring>
#include <vector>
#include <math.h>
#include <sstream>
#include <algorithm>
using namespace std;



int main() {

//    cout<<"Input : ";
    int n = 1;
//    cin>>n;
    
    vector<int> v(32,0);
    vector<vector<string>> commands;
    
    int flag = 0;
    
    while( n > 0){
        
        string input;
        getline(cin, input); // Read the entire line
        
        if(flag == 0){
            n = stoi(input);
            flag = 1;
            continue;
        }
        
        istringstream iss(input);
        vector<string> words;
        string word;
        
        while (iss >> word) {
            words.push_back(word);
        }
        
        commands.push_back(words);

        n--;
    }


    for(int i = 0 ; i < commands.size() ; i++){
        
        if( commands[i][0] == "ONE"){
            v[stoi(commands[i][1])] = 1;
        }
        
        else if ( commands[i][0] == "ZERO"){
            v[stoi(commands[i][1])] = 0;
        }
        
        else if ( commands[i][0] == "EITHER"){
            v[stoi(commands[i][1])] = ( v[stoi(commands[i][1])] || v[stoi(commands[i][2])] );
        }
        
        else if ( commands[i][0] == "BOTH"){
            v[stoi(commands[i][1])] = ( v[stoi(commands[i][1])] && v[stoi(commands[i][2])] );
        }
    }
    
    string ans = "";
    for(auto x : v)
//        cout<<char(x);
        ans = ans + to_string(x);
    
    reverse(ans.begin(), ans.end());
    cout<<ans;

    return 0;
}
