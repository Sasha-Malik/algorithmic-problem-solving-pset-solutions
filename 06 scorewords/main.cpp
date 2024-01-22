
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
    iss>>word;
    m = stoi(word);
    
    vector<int> score(m,0);
    unordered_map<string, int> dic;
    
    int counter = n;
    while(counter > 0){
        getline(cin, line);
        istringstream iss(line);
        string word;
        iss>>word;
        string w = word;
        iss>>word;
        int num = stoi(word);
        dic[w] = num;
        counter--;
    }

    counter = m;
    
    while(counter > 0){
        getline(cin, line);
        if(line == "."){
            counter--;
            continue;
        }
        
        istringstream iss(line);
        string word;
        
        while(iss>>word){
            if(dic.find(word) != dic.end())
                score[m - counter] += dic[word];
        }
    
    }
    
    for(auto x : score)
        cout<<x<<endl;

    return 0;
}
