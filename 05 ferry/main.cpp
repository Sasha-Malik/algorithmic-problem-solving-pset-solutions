
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <cctype>
#include <algorithm>
#include <queue>
using namespace std;

int main() {
//    cout<<"Input : "<<endl;
    int n , t , m;
    string line;
    getline(cin,line);
    istringstream iss(line);
    string word;
    iss>>word;
    n = stoi(word);
    iss>>word;
    t = stoi(word);
    iss>>word;
    m = stoi(word);
    
    queue<pair<int,int>> q_left;
    queue<pair<int,int>> q_right;
    int index = 0;
    
    int counter = m;
    while(counter > 0){
        getline(cin, line);
        istringstream iss(line);
        string word;
        pair <int, string> p;
        
        iss >> word;
        int time = stoi(word);
        iss >> word;
        if(word == "left"){
            q_left.push({time,index});
        }
           
        else
            q_right.push({time,index});
        
        index++;
        counter--;
    }
    
    vector<int> ans(m,0);
    
    int cur_time = 0; //time of ferry
    string cur_pos = "left"; // ferry position
    int cur_capacity = 0;
        
            
    while( !q_left.empty() || !q_right.empty() ){
        
        // next car on the other side
        if( (cur_pos == "left" &&
            ( q_left.empty()  ||  (!q_left.empty() && !q_right.empty() && q_left.front().first > cur_time && q_left.front().first > q_right.front().first ))) ||
            (cur_pos == "right" &&
            ( q_right.empty() ||  (!q_left.empty() && !q_right.empty() && q_right.front().first > cur_time && q_right.front().first > q_left.front().first ))) ){
                
            // waiting till the car arrives on the other side
            if (cur_pos == "left" && q_right.front().first > cur_time)
                cur_time = q_right.front().first;
            else if(cur_pos == "right" && q_left.front().first > cur_time)
                cur_time = q_left.front().first;
            
            cur_time = cur_time + t; //traveling to the other side
            if(cur_pos == "left") cur_pos = "right"; else cur_pos = "left"; // change cur_pos of the ferry
        }
        
        // next car on the same side
        else{

            //temp queue to mimick left and right
            queue<pair<int,int>>& cur_q = (cur_pos == "left") ? q_left : q_right;
            
            //waiting for the next car
            if (cur_q.front().first > cur_time)
                cur_time = cur_q.front().first;
            
            queue<pair<int,int>> on_ferry; // loading ferry
            
            //taking as many cars as the cap
            cur_capacity = 0;
            while(cur_capacity < n && !cur_q.empty() && cur_q.front().first <= cur_time){
                on_ferry.push(cur_q.front());
                cur_q.pop();
                cur_capacity++;
            }
            
            cur_time = cur_time + t; //travel for reaching
                
            // unloading ferry
            while(!on_ferry.empty()){
                ans[on_ferry.front().second] = cur_time;
                on_ferry.pop();
                cur_capacity--;
            }
                
            if(cur_pos == "left") cur_pos = "right"; else cur_pos = "left"; // change cur_pos of the ferry
        }
            
    }
    
    for(auto a : ans)
        cout<<a<<endl;

    return 0;
}
