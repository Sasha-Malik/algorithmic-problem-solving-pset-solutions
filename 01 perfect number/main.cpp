
#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <math.h>
#include <unordered_map>
using namespace std;

int main(int argc, const char * argv[]) {

//    cout<<"input : ";
    string input;
    getline(cin, input);
    
    long n = stoul(input);

    if(n == 1){
        cout<<"NOT PERFECT\n";
        return 0;
    }
        
    vector<long> nums;
    int sq = sqrt(n);
    
    unordered_map<long,int> map;
  
    for(long i = 1; i <= sq ; i++)
    {
        if(n%i == 0){
            
            if(map.find(i) == map.end()){
                map[i] = 1;
                nums.push_back(i);
            }
            
            if(map.find(n/i) == map.end() && n/i != n ){
                map[n/i] = 1;
                nums.push_back(n/i);
            }
                
        }
            
    }
    
    long sum = 0;
    for(auto x : nums){
//        cout<<x<<endl;
        sum+=x;
    }
    
    if(sum == n)
        cout<<"PERFECT\n";
    else
        cout<<"NOT PERFECT\n";
    
    return 0;
}
