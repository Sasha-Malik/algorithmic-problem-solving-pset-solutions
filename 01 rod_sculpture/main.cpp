
#include <iostream>
#include <vector>
#include <sstream>
#include <string>
using namespace std;

int main(int argc, const char * argv[]) {
//    cout << "Input : ";
    string input;
    getline(cin, input);
    
//    int l = stoi(input);
    
    getline(cin, input);
    istringstream iss(input);
            
    string token;
    vector<string> temp;
            
    while (iss >> token) {
        temp.push_back(token);
    }
    
    string dir = "+x";
    
    for(auto turn : temp){
        
        if(turn == "No")
            continue;
        
        else if((dir == "+z" || dir == "-z") && (turn == "+y" || turn == "-y")){
            continue;
        }
        
        else if(dir == "+z" ){
            if(turn == "+z")
                dir = "-x";
            if(turn == "-z")
                dir = "+x";
        }
        
        else if(dir == "-z" ){
            if(turn == "+z")
                dir = "+x";
            if(turn == "-z")
                dir = "-x";
        }
        
        
        else if((dir == "+y" || dir == "-y") && (turn == "+z" || turn == "-z")){
            continue;
        }
        
        else if(dir == "+y" ){
            if(turn == "+y")
                dir = "-x";
            if(turn == "-y")
                dir = "+x";
        }
        
        else if(dir == "-y" ){
            if(turn == "+y")
                dir = "+x";
            if(turn == "-y")
                dir = "-x";
        }
        
        else if(dir == "+x"){
            dir = turn;
        }
        
        else if(dir == "-x"){
                    
            if(turn[0] == '-')
                turn[0] = '+';
                        
            else if(turn[0] == '+')
                turn[0] = '-';
            
            dir = turn;
        }
            
    }
    
    cout<<dir;
    
    return 0;
}
