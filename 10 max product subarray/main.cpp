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
#include "bigint.h"
using namespace std;

int main() {
    string line;
    getline(cin,line);
    int n = stoi(line);
    getline(cin,line);
    string word;
    stringstream iss(line);
    vector<int> nums;
    while(iss>>word){
        nums.push_back(stoi(word));
    }
    
    if(nums.size() == 1){
        cout<<nums[0]<<endl;
        return 0;
    }
        
    vector<pair<bigint,bigint>> prod (nums.size());
    
    bigint maximum(nums[0]);
    bigint max1 = 1, min1 = 1;
    
    prod[0] = {nums[0] , nums[0]};

    for(int i = 1 ; i < nums.size() ; i++)
    {
        bigint nums1 = nums[i];
        bigint nums2 = nums[i] * prod[i-1].first;
        bigint nums3 = nums[i] * prod[i-1].second;
    
        if(nums1 >= big_max(nums2,nums3))
            max1 = nums1;

        else if (nums2 >= big_max(nums1 , nums3))
            max1 = nums2;

        else if (nums3 >= big_max(nums1 , nums2))
            max1 = nums3;

        if(nums1 <= big_min(nums2,nums3))
            min1 = nums1;

        else if (nums2 <= big_min(nums1 , nums3))
            min1 = nums2;

        else if (nums3 <= big_min(nums1 , nums2))
            min1 = nums3;

        prod[i].first = min1;
        prod[i].second = max1;

        if(maximum < big_max(prod[i].first , prod[i].second))
            maximum = big_max(prod[i].first , prod[i].second);
    }

    cout<<maximum<<endl;

    return 0;
}
