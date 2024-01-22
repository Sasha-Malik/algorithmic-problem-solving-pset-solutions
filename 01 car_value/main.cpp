
#include <iostream>
#include <vector>
#include <sstream>
#include <string>
using namespace std;

int main(int argc, const char * argv[]) {
//    cout << "Input : ";
    string input;
    vector<vector<double>> inputs;
  
    getline(cin, input);
    istringstream iss(input);
            
    string token;
    vector<string> temp;
            
    while (iss >> token) {
        temp.push_back(token);
    }
    
    double duration = stod(temp[0]);
    double downp = stod(temp[1]);
    double amount = stod(temp[2]);
    int len = stod(temp[3]);
    int n = len;
     
    while(n > 0){
        getline(cin, input);
        istringstream iss(input);
                
        string token;
        vector<double> temp;
                
        while (iss >> token) {
            temp.push_back(stod(token));
        }
        
        inputs.push_back(temp);
        n--;
    }

    //at month 0
    double monthly_p = amount/duration; // monthly payment
    double cur_interest = inputs[0][1];
    double owed = amount; // owed value
    double cur = amount + downp; // current value
    cur = cur - (cur * inputs[0][1]);
    int month = 0; // completed month number

        
    if(cur > owed){
        cout<<"0 months\n";
        return 0;
    }
    
    int cur_index = 1;
    
    for(int i = 1 ; i <= duration ; i++)
    {
        
        if(cur_index < len ){
            
            if(inputs[cur_index][0] == i){
                cur_interest = inputs[cur_index][1];
                cur_index++;
            }
        }
   
        owed = owed - monthly_p;
        cur = cur - (cur * cur_interest);
        
        month = i;
        
        if(cur > owed){
            break;
        }
    }
    
    if(month == 1)
        cout<< month <<" month\n";
    else
        cout<< month <<" months\n";
    return 0;
}
