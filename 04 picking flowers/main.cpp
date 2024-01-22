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

int main(){
//    cout<<"Input : ";
    string line;
    getline(cin, line);
    
    vector<int> n;
    istringstream iss(line);
    string word;
    while(iss>> word){
        n.push_back(stoi(word));
    }
    
    vector<vector<int>> v;
   
    for(int i = 0 ; i < 3 ; i++){
        getline(cin, line);
        vector<int> temp;
        istringstream iss(line);
        while(iss>> word){
            temp.push_back(stoi(word));
        }
        v.push_back(temp);
    }

    unordered_map<int, vector<char>> map;
    
    for(int i = 0 ; i < 3 ; i++){
        for(int j = 0 ; j < v[i].size() ; j++){
        
            if(i == 0){
                if(map.find(v[i][j]) == map.end())
                    map[v[i][j]] = {'m'};
                else
                    map[v[i][j]].push_back('m');
            }
            if(i == 1){
                if(map.find(v[i][j]) == map.end())
                    map[v[i][j]] = {'a'};
                else
                    map[v[i][j]].push_back('a');
            }
            if(i == 2){
                if(map.find(v[i][j]) == map.end())
                    map[v[i][j]] = {'l'};
                else
                    map[v[i][j]].push_back('l');
            }
        }
    }
    
    int m_has = 0, a_has = 0, l_has = 0;
    int m_not = 0, a_not = 0, l_not = 0;

    for (const auto& entry : map) {
        bool m_picked = false, a_picked = false, l_picked = false;
        for (char person : entry.second) {
            if (person == 'm')
                m_picked = true;
            else if (person == 'a')
                a_picked = true;
            else
                l_picked = true;
        }
            
        if (m_picked && !a_picked && !l_picked)
            m_has++;
        if (a_picked && !m_picked && !l_picked)
            a_has++;
        if (l_picked && !a_picked && !m_picked)
            l_has++;
        
        if (!m_picked && a_picked && l_picked)
            m_not++;
        if (!a_picked && m_picked && l_picked)
            a_not++;
        if (!l_picked && a_picked && m_picked)
            l_not++;
    }
    
//    cout<<endl;
    cout << m_has <<" "<< m_not <<endl;
    cout << a_has <<" "<< a_not <<endl;
    cout << l_has <<" "<< l_not ;

    return 0;
}

