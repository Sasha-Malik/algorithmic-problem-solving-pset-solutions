
#include <iostream>
#include <vector>
#include <sstream>
#include <string>
using namespace std;

int fib(int n){
    
    if(n==1)
        return 1;
    
    if(n==2)
        return 1;
    
    return fib(n-1) + fib(n-2);
}

int main(int argc, const char * argv[]) {

//    cout<<"input : ";
    string input;
    getline(cin, input);
    int n = stoi(input);
       
    cout<<fib(n)<<"\n";
    return 0;
}


