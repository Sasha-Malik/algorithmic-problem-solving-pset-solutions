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

string toBinary(unsigned long long number) {
   bitset<64> binary(number);
   return binary.to_string();
}

unsigned long long toDecimal(string binaryString) {
   bitset<64> bits(binaryString);
   return bits.to_ullong();
}

int main() {
    
   
   string line;
   getline(cin,line);
   stringstream iss(line);
   string word;
   iss>>word;
   long long int n = stoull(word);
   iss>>word;
   long long int l = stoull(word);
   iss>>word;
   long long int r = stoull(word);
   iss>>word;

    string start = toBinary(r);
       
    string str_n = toBinary(n);
       
    string str_l = toBinary(l);
       
    string str_r = toBinary(r);

       
    bool flip = 0;

    //make as many 1's we can from the right, without exceding R at any point
    for(int i = 0; i < 64; i++){
            
        if(str_n[i] == '1' && start[i] == '1'){
                
            if(flip == 0){
                    
                start[i] = '0';
                    
                string temp = start;
                for (int j = i + 1; j < 64; j++)
                    temp[j] = '1';
                        
                if (toDecimal(temp) < l)
                    start[i] = '1';
                        
                else{
                    start = temp;
                    flip = 1;
                }
                        
            }
                    
                
            else if(flip == 1){
                    
                start[i] = '0';
                if(toDecimal(start) < l)
                    start[i] = '1';
            }
        }
    }
        
       
    cout<<toDecimal(start)<<endl;
  
   return 0;
// credits : chen
}
