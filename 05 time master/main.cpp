#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <cctype>
#include <algorithm>
#include <queue>
#include <set>
using namespace std;


struct Reminder {
    int id;
    int interval;
    int nextAlertTime;

    Reminder(int id, int interval) : id(id), interval(interval), nextAlertTime(interval) {}
};

struct CompareReminders {
    bool operator()(const Reminder& r1, const Reminder& r2) {
        if (r1.nextAlertTime == r2.nextAlertTime) {
            return r1.id > r2.id;
        }
        return r1.nextAlertTime > r2.nextAlertTime;
    }
};

int main() {
    
    vector<Reminder> reminders;
    priority_queue<Reminder, vector<Reminder>, CompareReminders> alertQueue;

    string line;
    getline(cin,line);
    vector<pair<int,int>> v;
    while(line != "#"){
        
        istringstream iss (line);
        string word;
        iss>>word;
        iss>>word;
        int id = stoi(word);
        iss>>word;
        int interval = stoi(word);
        reminders.push_back(Reminder(id, interval));
        getline(cin,line);
    }
    
    getline(cin,line);
    int n = stoi(line);
    
    for (const Reminder& reminder : reminders) {
          alertQueue.push(reminder);
      }

      for (int i = 0; i < n; i++) {
          Reminder top = alertQueue.top();
          alertQueue.pop();
          cout << top.id << endl;
          top.nextAlertTime += top.interval;
          alertQueue.push(top);
      }
    
    
    return 0;
}
