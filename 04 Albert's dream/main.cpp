#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <cctype>
#include <algorithm>

using namespace std;

int main() {
//    cout<<"input :";
    string line;
    vector<string> words; // Vector to store words

    // Read and process each line of input until EOF is encountered
    while (!cin.eof()) {
        getline(cin, line);
        istringstream iss(line);
        string word;

        // Split the line into words using spaces
        while (iss >> word) {
            
            string temp = word;
            string temp_word = "";
            for(auto t : temp){
                if(isalpha(t))
                    temp_word = temp_word + t;
            }
            
            words.push_back(temp_word); // Store each word in the vector
        }
    }
    
    unordered_map<string, int> map;
    for(auto w : words){
        
        string temp = "";
        for(auto x : w){
            char y = towlower(x);
            temp = temp + y;
        }
    
        if( map.find(temp) == map.end()){
            map[temp] = 1;
        }
    }
    
    vector<string> ans;
    for(auto x : map){
        ans.push_back(x.first);
    }
    
    sort(ans.begin(),ans.end());
    
    for(auto x : ans){
        cout<<x<<endl;
    }

    return 0; // Exit successfully
}
