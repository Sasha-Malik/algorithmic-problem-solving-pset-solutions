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


bool canDivide(const vector<int> &tasks, long maxLoad, int m) {
    
    long currentLoad = 0;
    int partitions = 1; // start with one partition

    int tasksRemaining = tasks.size(); //  remaining number of tasks

    // greedy from the end
    for (int i = tasks.size() - 1; i >= 0; --i) {
        
        //remaining partitions : m - partitions
        
        if ((currentLoad + tasks[i] <= maxLoad) && (tasksRemaining > m - partitions)) {
            currentLoad += tasks[i];
        }
        else {
            //  not enough tasks left for the remaining partitions
            if (partitions == m) {
                return false;
            }

            // new partition with the current task
            currentLoad = tasks[i];
            partitions++;
        }
        tasksRemaining--;
        
    }
    
    return partitions == m;
}

int main() {
    string line;
    getline(cin,line);
    stringstream iss(line);
    string word;
    iss>>word;
    int n = stoi(word);
    iss>>word;
    int m = stoi(word);
        
    getline(cin,line);
    stringstream is(line);
    
    vector<int> nums;
    int max_task = 0;
    long sum = 0;
        
    while(is>>word){
        nums.push_back(stoi(word));
        sum += stoi(word);
        max_task = max(max_task, stoi(word));
    }
    
    
    long left = max_task;
    long right = sum;
    
    long bestMaxLoad = right;

    while (left <= right) {
        
        long mid = left + (right - left) / 2;
  
        if (canDivide(nums, mid, m)) {
            bestMaxLoad = mid;
            right = mid - 1;
        }
        else
            left = mid + 1;
    }
    
    cout<<bestMaxLoad<<endl;

    return 0;
}
