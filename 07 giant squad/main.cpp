#include <iostream>
#include <unordered_map>
#include <cstring>
#include <vector>
#include <math.h>
#include <sstream>
#include <algorithm>
#include <stack>
#include <limits.h>
using namespace std;


int main() {
    int n;
    string line;
    getline(cin,line);
    istringstream iss(line);
    string word;
    
    iss>>word;
    n = stoi(word);

    vector<int> v;
 
    while(iss>>word){
        v.push_back(stoi(word));
    }

    cout<<v[n/2]<<endl;
    
    return 0;
}
