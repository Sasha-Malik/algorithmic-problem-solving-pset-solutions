#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>

using namespace std;

// Define a map to store operator precedence
unordered_map<char, int> precedence = {
    {'+', 1},
    {'-', 1},
    {'*', 2},
    {'/', 2}
};

string infixToRPN(const string& infix) {
    string rpn = "";
    stack<char> operators;

    for (char ch : infix) {
        if (isdigit(ch)) {
            rpn += ch;
        } else if (ch == '(') {
            operators.push(ch);
        } else if (ch == ')') {
            while (!operators.empty() && operators.top() != '(') {
                rpn += operators.top();
                operators.pop();
            }
            operators.pop(); // Remove the '('
        } else {
            // Operator encountered
            while (!operators.empty() && precedence[ch] <= precedence[operators.top()]) {
                rpn += operators.top();
                operators.pop();
            }
            operators.push(ch);
        }
    }

    // Pop remaining operators from the stack
    while (!operators.empty()) {
        rpn += operators.top();
        operators.pop();
    }

    return rpn;
}

int main() {
    string infix;
    string line;
//    cout << "Enter :" << endl;
    
    while(getline(cin, line)){
        infix = infix + line;
    }
    
    // Convert the infix expression to RPN
    string rpn= infixToRPN(infix);

    cout<<rpn<<endl;

    return 0; // Exit successfully
}
