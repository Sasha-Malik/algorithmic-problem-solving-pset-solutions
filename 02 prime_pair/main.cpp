#include <iostream>
#include <unordered_map>
#include <cstring>
#include <vector>
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
    
//    cout<<"Input : ";
    int n;
    cin>>n;
    
    int count = 0;
                                          
    vector<int> v = sieve_of_eratosthenes(20000000);
    
    int len = v.size();
    for(int i = 0 ; i < len ; i++){
        
        if(v[i] + 2 == v[i+1])
            count++;
        
        if(count == n){
            cout<<"("<<v[i]<<", "<<v[i+1]<<")"<<endl;
            break;
        }
            
    }
    
//    cout<<"("<<ans[ans.size()-1].first<<", "<<ans[ans.size()-1].second<<")"<<endl;
        
    return 0;
}
