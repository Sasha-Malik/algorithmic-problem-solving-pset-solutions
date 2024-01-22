
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
    int n, m;
    string input;
    getline(cin,input);
    vector<int> temp;
    istringstream iss(input);
    string word;
    while(iss >> word){
        temp.push_back(stoi(word));
    }
    
    n = temp[0];
    m = temp[1];
    
    vector<vector<int>> one_time;
    vector<vector<int>> repeat;

    while(n>0){
        
        string input;
        vector<int> row;
        getline(cin,input);
        
        istringstream iss(input);
        string temp;
        while(iss >> temp){
            row.push_back(stoi(temp));
        }
        one_time.push_back(row);
        n--;
    }
    
    while(m>0){
        string input;
        vector<int> row;
        getline(cin,input);
        istringstream iss(input);
        string temp;
        while(iss >> temp){
            row.push_back(stoi(temp));
        }
        repeat.push_back(row);
        m--;
    }

    
    unordered_map<int, int> map;
    int check = 0;
    
    for(int i = 0 ; i < one_time.size() ; i++){
 
        for(int j = one_time[i][0] ; j <= one_time[i][1] ; j++){
            
            // start or end
            if( map.find(j) == map.end() && (j == one_time[i][0] || j ==  one_time[i][1]) ){
                map[j] = 2;
            }
            
            //not found
            else if( map.find(j) == map.end() ){
                map[j] = 1;
            }
            
            // already a start/end
            else if(map[j] == 2  && (j == one_time[i][0] || j ==  one_time[i][1])){
                map[j] = 1;
            }
            else{
                check = 1;
                break;
            }
        }
        if(check == 1)
            break;
    }
    
    if(check == 1){
        cout<<"CONFLICT"<<endl;
        return 0;
    }
    
    
    for(int i = 0; i < repeat.size() ; i++){
        
        for(int j = repeat[i][0] ; j <= 1000000 ; j += repeat[i][2]){
  
            for(int k = j ; k <= j + repeat[i][1] - repeat[i][0] ; k++ ){
                
                //start or end
                if( map.find(k) == map.end() && (k == j || k == j + repeat[i][1] - repeat[i][0]) ){
                    map[k] = 2;
                }
                
                // does not exist
                else if(map.find(k) == map.end()){
                    map[k] = 1;
                }
                
                //already a start or end
                else if(map[k] == 2  && (k == j || k == j + repeat[i][1]- repeat[i][0])){
                    map[k] = 1;
                }
                
                else{
                    check = 1;
                    break;
                }
                
            }
            
            if(check == 1)
                break;
        }
        
        if(check == 1)
            break;
        
    }
    
    if(check == 1){
        cout<<"CONFLICT"<<endl;
        return 0;
    }
    
    cout<<"NO CONFLICT"<<endl;
    return 0;
}
