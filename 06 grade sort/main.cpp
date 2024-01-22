
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
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    string line;
    getline(cin,line);
    N = stoi(line);
    
    const int MAX_SCORE = 100;
    const int MAX_N = 10000010;

    vector<int> count(MAX_SCORE + 1,0);

    for (int i = 0; i < N; i++) {
        int score;
        cin >> score;
        count[score]++;
    }


    for (int score = 0; score <= MAX_SCORE; score++) {
        while (count[score] > 0) {
            cout << score;
            if (N > 1) {
                cout << " ";
                N--;
            }
            count[score]--;
        }
    }

    cout << endl;

    return 0;
}
