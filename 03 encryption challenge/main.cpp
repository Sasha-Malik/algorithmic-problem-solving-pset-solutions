
#include <iostream>
#include <unordered_map>
#include <cstring>
#include <vector>
#include <math.h>
#include <sstream>
#include <algorithm>
#include <stack>
using namespace std;



int main() {
//    cout<<"Input : ";
    string s;
    getline(cin,s);
    string n;
    getline(cin, n);
    string input;
    getline(cin,input);
    
    // Remove the leading '[' and trailing ']' characters
       if (input.front() == '[' && input.back() == ']') {
           input = input.substr(1, input.length() - 2);
       }

       istringstream iss(input);
       vector<int> numbers;
       int number;
       char comma;

       while (iss >> number) {
           numbers.push_back(number);
           if (!(iss >> comma) && iss.eof()) {
               break;
           }
       }
    
    int error = 0;

    int l = 0;
    int r = numbers.size()-1;

    char dir = 'l';
    for(auto x : s){
        
        if(x == 'D'){
            if(dir == 'l')
                l++;
            else
                r--;
            
            error++;
        }
        
        if(error == numbers.size() + 1){
            cout<<"error"<<endl;
            return 0;
        }
        
        if(x == 'R'){
            if(dir == 'l')
                dir = 'r';
            else
                dir = 'l';
        }
    }
    
    string ans = "[";

    if (dir == 'l'){
        for(int i = l ; i <= r ; i++){
            ans = ans +  to_string(numbers[i]);
            ans = ans + ",";
        }
    }
    else{
        for(int i = r ; i >= l ; i--){
            ans = ans + to_string(numbers[i]);
            ans = ans + ",";
        }
    }
    
    if(error != numbers.size())
        ans.pop_back();
    
    ans = ans + "]";
    
    cout<<ans<<endl;
    return 0;
}
