#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string> tokens) {
        map<string,function<int (int,int)>> operators = {
                {"+", [](int a, int b) {return a+b;}}, 
                {"-", [](int a, int b) {return a-b;}}, 
                {"*", [](int a, int b) {return a*b;}}, 
                {"/", [](int a, int b) {return a/b;}},
            };
        stack<int> st;
        for(string tk : tokens) {
            if(operators.find(tk) != operators.end()) {
                int n2 = st.top(); st.pop();
                int n1 = st.top(); st.pop();
                st.push(operators[tk](n1,n2));
            }
            else st.push(stoi(tk));
        }
        return st.top();
    }
};


int main() {
    Solution s;
    cout<<s.evalRPN({"10","6","9","3","+","-11","*","/","*","17","+","5","+"})<<endl;
    return 0;
}