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
    int M, N;
    cin>>M>>N;

    vector<vector<int>> dp(N + 1, vector<int>(M + 1, -1));
    dp[0][0] = 0;

    for (int i = 1; i <= N; ++i) {
        int k;
        cin >> k;
        vector<int> costs(k);
        for (int &cost : costs) cin >> cost;

        for (int j = 0; j <= M; ++j) {
            if (dp[i-1][j] != -1) {
                for (int cost : costs) {
                    if (j + cost <= M) {
                        dp[i][j + cost] = max(dp[i][j + cost], dp[i-1][j] + cost);
                    }
                }
            }
        }
    }

    int result = *max_element(dp[N].begin(), dp[N].end());
    
    if (result == -1)
        cout<<"no solution"<<endl;
    
    else
        cout<<result<<endl;
    

    return 0;
}
