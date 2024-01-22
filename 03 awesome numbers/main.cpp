
#include <iostream>
#include <unordered_map>
#include <cstring>
#include <vector>
#include <math.h>
#include <sstream>
#include <algorithm>
#include <stack>
using namespace std;


vector<int> sieve_of_eratosthenes(int n)
{
   vector<int> ans;
   vector<bool> is_prime(n + 1, true);
   is_prime[0] = is_prime[1] = false;
   for (int p = 2; p * p <= n; p++) {
       if (is_prime[p]) {
           for (int i = p * p; i <= n; i += p) {
               is_prime[i] = false;
           }
       }
   }
   for (int i = 2; i <= n; i++) {
       if (is_prime[i]) {
           ans.push_back(i);
       }
   }
    
    return ans;
}

int main() {
    
    int n;
    cin>>n;
    
    int count = 0;
                                          
    vector<int> v = sieve_of_eratosthenes(n);
    
    for(auto x : v){
        if(x%10 == 1)
            count++;
    }
    
    cout<<count<<endl;
        
    return 0;
}
