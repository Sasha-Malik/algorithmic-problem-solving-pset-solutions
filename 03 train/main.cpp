#include <iostream>
#include <vector>
#include <stack>
#include <sstream>

using namespace std;

int main() {
    int n;
    string input;
    getline(cin,input);
    n = stoi(input);
    

    while (true) {
        getline(cin, input);
        if (input == "0")
            break;

        istringstream iss(input);
        vector<int> desired_order(n);

        for (int i = 0; i < n; i++) {
            iss >> desired_order[i];
        }

        stack<int> station;
        int coach = 1;
        bool feasible = true;

        for (int i = 0; i < n; ++i) {
            while (coach <= n && (station.empty() || station.top() != desired_order[i])) {
                station.push(coach);
                coach++;
            }

            if (!station.empty() && station.top() == desired_order[i]) {
                station.pop();
            }
            else {
                feasible = false;
                break;
            }
        }

        if (feasible) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }

    return 0;
}
