
#include <iostream>
#include <vector>
#include <sstream>
#include <string>
using namespace std;

int main(int argc, const char * argv[]) {

//    cout<<"input : ";
    string input;
    getline(cin, input);
    int n = stoi(input);
    
    if(n == 1){
        cout<<"0\n";
        return 0;
    }
    
    if(n == 2){
        cout<<"1\n";
        return 0;
    }
       
    vector<long> v;
    v.push_back(0);
    v.push_back(1);
    
    for(int i = 2 ; i <= n ; i++)
        v.push_back(v[i-1] + v[i-2]);
    
    
    
    cout<<v[n-1]<<"\n";
    
    return 0;
}
