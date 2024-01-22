#include <iostream>
#include <unordered_map>
#include <cstring>
#include <vector>
#include <math.h>
#include <sstream>
#include <algorithm>
#include <stack>
#include <limits.h>
#include <queue>
#include <fstream>
#include <bitset>
using namespace std;

int main() {
    string line;
    getline(cin,line);
    stringstream iss(line);
    string word;
    iss>>word;
    int m = stoi(word);
    iss>>word;
    int t = stoi(word);
    
    vector<string> v1;
    vector<string> v2;
    
    getline(cin, line);
    stringstream is1(line);
    while(is1>>word){
        v1.push_back(word);
    }
    
    getline(cin, line);
    stringstream is2(line);
    while(is2>>word){
        v2.push_back(word);
    }
    
    unordered_map<string, int> notes = {
        {"A", 0}, {"A#", 1}, {"Bb", 1}, {"B", 2}, {"Cb", 2}, {"B#", 3}, {"C", 3}, {"C#", 4}, {"Db", 4},
        {"D", 5}, {"D#", 6}, {"Eb", 6}, {"E", 7}, {"Fb", 7}, {"E#", 8}, {"F", 8}, {"F#", 9}, {"Gb", 9},
        {"G", 10}, {"G#", 11}, {"Ab", 11}};
    
    vector<int> v_m;
    for(int i = 1 ; i < m; i++){
        
        int semitone = (notes[v1[i]] - notes[v1[i-1]] + 12) % 12;
        v_m.push_back(semitone);
    }
    
    vector<int> v_t;
    for(int i = 1 ; i < t; i++){
        
        int semitone = (notes[v2[i]] - notes[v2[i-1]] + 12) % 12;
        v_t.push_back(semitone);
    }
    
    int m_size = v_m.size();
    int t_size = v_t.size();
    int flag = 0;
    
    if(t_size != 0){
        
        for (int i = 0; i <= m_size - t_size; ++i) {
            bool match = true;
            for (int j = 0; j < t_size; ++j) {
                if (v_m[i + j] != v_t[j]) {
                    match = false;
                    break;
                }
            }
            
            if(match == true){
                flag = 1;
                break;
            }
        }
        
        if(flag == 1)
            cout<<"S";
        else
            cout<<"N";
        
//        unordered_map<int, int> cur_freq;
//        unordered_map<int, int> t_freq;
//        for(auto s : v_t)
//            ++t_freq[s];
//        
//        int l = 0, r = 0;
//        bool match = false;
//        
//        while(l<=r){
//            
//            int flag = 0;
//            
//            //window size increasing
//            if(t_freq.find(v_m[r]) != t_freq.end()){
//                
//                if(cur_freq.find(v_m[r]) == cur_freq.end()){
//                    cur_freq[v_m[r]]++;
//                    r++;
//                    flag = 1;
//                }
//                else if(cur_freq[v_m[r]] + 1 <= t_freq[v_m[r]] ){
//                    cur_freq[v_m[r]]++;
//                    r++;
//                    flag = 1;
//                }
//                
//                if( r - l == t_size){
//                    match = true;
//                    break;
//                }
//            }
//           
//            if(flag == 0){
//                cur_freq[v_m[l]]--;
//                l++;
//            }
//            
//        }
//        
//        if(match == true)
//            cout<<"S";
//        else
//            cout<<"N";
        
        
        
     
    }
        
    // check if the character in T exists in M
    else{
        
        int semitone1 = notes[v2[0]];
        for (auto note2 : v1) {
            
            int semitone2 = notes[note2];
            if ((semitone2 - semitone1 + 12) % 12 == 0)
                flag = 1;
        }
                
        if(flag == 1)
            cout<<"S";
        else
            cout<<"N";
    }
    
    
    return 0;
}
