#include <iostream>
#include <unordered_map>
#include <cstring>
#include <vector>
#include <math.h>
#include <sstream>
#include <algorithm>
#include <stack>
#include <queue>
#include <limits.h>
#include <iterator>
using namespace std;

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    string line;
    getline(cin,line);
    n = stoi(line);

    vector<pair<int, int>> problems(n);

    for (int i = 0; i < n; i++) {
            cin>>problems[i].first>>problems[i].second;
    }

    sort(problems.begin(), problems.end(), [](const pair<int, int>& p1, const pair<int, int>& p2) {
        // Sort by (bi - ai) in ascending order
        return p1.second > p2.second;
    });


    int currentTime = 0;
    int totalTime = 0;
        
    for (int i = 0; i < n; i++) {
           currentTime += problems[i].first;
           totalTime = max(totalTime, currentTime + problems[i].second);
    }

    cout<<totalTime<<endl;

    return 0;
}
