
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
    m = stoi(line);
    getline(cin,line);
    n = stoi(line);
    
    vector<int> strikes;
    int count = 0;
    
    int counter = n;
    while(counter > 0){
        getline(cin, line);
        istringstream iss(line);
        string word;
        iss>>word;
        int num = stoi(word);
        
        
//        if(num%6 != 0 && num%7 != 0)
            strikes.push_back(num);
        
        counter--;
    }
    
    
    int totalDaysWithoutSubway = 0;
    for (int day = 1; day <= m; day++) {
            
        if (day % 7 == 6 || day % 7 == 0) { // Friday or Saturday
            continue;
        }

        bool subwayOperates = true;

        // Check if any labor union is on strike on this day
        for (auto x : strikes) {
            if (day % x == 0) {
                subwayOperates = false;
                break;
            }
        }

        if (!subwayOperates) {
            totalDaysWithoutSubway++;
        }
    }

    cout << totalDaysWithoutSubway << endl;
  
    return 0;
}
