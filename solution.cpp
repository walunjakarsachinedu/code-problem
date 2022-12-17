#include <bits/stdc++.h>
#include "print.cpp"
using namespace std;

// 150. Evaluate Reverse Polish Notation
class Solution {
public:
  int evalRPN(vector<string>& tokens) {
    stack<long> operands;
    for(int i=0; i<tokens.size(); i++) {
      if(isOperator(tokens[i])) {
        long o2 = operands.top(); operands.pop();
        long o1 = operands.top(); operands.pop();
        operands.push(evaluate(tokens[i], o1, o2));
      }
      else operands.push(stoi(tokens[i]));
    }
    return operands.top();
  }
  //  

  bool isOperator(string op) {
    return op=="-" || op=="+" || op=="*" || op=="/";
  }

  long evaluate(string optr, long o1, long o2) {
    if(optr == "*") return o1 * o2;
    if(optr == "/") return o1 / o2;
    if(optr == "+") return o1 + o2;
    if(optr == "-") return o1 - o2;
    return 0;
  }
};

int main() {
  vector<string> tokens = {"2","1","+","3","*"};
  cout << Solution().evalRPN(tokens) << endl;
  return 0;
}