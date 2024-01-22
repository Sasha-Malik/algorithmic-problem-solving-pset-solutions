
#include <iostream>
#include <vector>
#include <sstream>
#include <string>
using namespace std;

int main(int argc, const char * argv[]) {

    string input;
  
    getline(cin, input);
    int a = stoi(input);
    getline(cin, input);
    int b = stoi(input);
       
    long c = a + b;
    cout<<c<<endl;
    return 0;
}
