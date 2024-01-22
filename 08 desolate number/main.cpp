
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


    string line;
    getline(cin,line);
    stringstream iss(line);
    string word;
    iss>>word;
    int countOnes = stoi(word);
    iss>>word;
    int countZeros = stoi(word);
    
    deque<int> binarySequence;
    
    // Add two 1s and one 0 repeatedly until it's not possible
    while (countOnes >= 2 && countZeros >= 1) {
        binarySequence.push_back(1);
        binarySequence.push_back(0);
        binarySequence.push_back(1);
        countOnes -= 2;
        countZeros -= 1;
    }
    
    //add 01 in the front
     while(countOnes > 0 && countZeros > 0){
         binarySequence.push_front(1);
         binarySequence.push_front(0);
       
         countOnes--;
         countZeros--;
     }
         
    //remaining 1 in the back
    if(countZeros == 0){
        while(countOnes > 0){
            binarySequence.push_back(1);
            countOnes--;
        }
    }
    
    //remaining 0 in the front
    else if(countOnes == 0){
        while(countZeros > 0){
            binarySequence.push_front(0);
            countZeros--;
        }
    }


    long long int ans = 0, base = 1;
    while(!binarySequence.empty())
    {
        ans += binarySequence.back() * base;
        base *= 2;
        binarySequence.pop_back();
    }
    cout<<ans<<endl;
    
    return 0;
}


