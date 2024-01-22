#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
#include <fstream>
#include <sstream>
#include <queue>

using namespace std;

int main(){
//    cout<<"input :";
    string line;
//    ifstream inputFile("input.txt"); // Open the input file
    
    int n = 1;
    int flag = 1;
    
    
    vector<int> ans;
    priority_queue<int> max;
    priority_queue <int, vector<int>, greater<int>> min;
    
    unordered_map<int, int> freq;
    
    // Read and process each line of input until EOF is encountered
    while (true) {
        
        if(flag == 1){
            getline(cin, line);
            n = stoi(line);
            flag = 0;
            continue;
        }
        
        getline(cin, line);
        istringstream iss(line);
        string word;
        
        vector<int> v;
        int check = 1;
        
        while(iss >> word){
            
            //skipping the first number (k)
            if(check == 1){
                check = 0;
                continue;
            }
            
            min.push(stoi(word));
            max.push(stoi(word));
            
            if(freq.find(stoi(word)) == freq.end())
                freq[stoi(word)] = 1;
            else
                freq[stoi(word)]++;
        }

        while(freq[max.top()] <= 0){
            max.pop();
        }

        int max_num = max.top();
        freq[max.top()]--;
        max.pop();

        while(freq[min.top()] <= 0){
            min.pop();
        }

        int min_num = min.top();
        freq[min.top()]--;
        min.pop();

        ans.push_back(max_num - min_num);
        
        n--;
        if(n == 0)
            break;
    }
//    inputFile.close();
    
    for(auto x : ans)
        cout<<x<<endl;
    
    return 0;
}
