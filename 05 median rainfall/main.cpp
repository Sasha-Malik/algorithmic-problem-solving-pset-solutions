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
    vector<long> data;
    string line;
    vector<long> v;
//    getline(cin,line);
   
    while (getline(cin, line)) {
        line.erase(remove_if(line.begin(), line.end(), ::isspace), line.end()); // Remove spaces
        if (line.empty())
            continue; // Skip empty lines
        long n = stol(line);
        v.push_back(n);
    }
    priority_queue<long> lower_half; // Max heap for the lower half
    priority_queue<long, vector<long>, greater<long>> upper_half; // Min heap for the upper half

        for (long i = 0; i < v.size(); i++) {
            long rainfall = v[i];

            if (lower_half.empty() || rainfall <= lower_half.top()) {
                lower_half.push(rainfall);
            } else {
                upper_half.push(rainfall);
            }

            // Ensure the sizes of the heaps are balanced
            if (lower_half.size() > upper_half.size() + 1) {
                upper_half.push(lower_half.top());
                lower_half.pop();
                }
            
            else if (upper_half.size() > lower_half.size()) {
                lower_half.push(upper_half.top());
                upper_half.pop();
                }

                // Calculate and prlong the current median
                if (lower_half.size() == upper_half.size()) {
                    cout<<(lower_half.top() + upper_half.top()) / 2<<endl;
                }
                else
                    cout<<lower_half.top() << endl;
            
        }

        return 0;
    }
