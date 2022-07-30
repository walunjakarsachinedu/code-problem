#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        stack<string> st;
        vector<string> res;
        st.push("(");
        while(!st.empty()) {
            string str = st.top(); st.pop();
            int l=0,r=0;
            for(char ch : str)  if(ch == '(') ++l; else ++r;
            if(l == n) {
                while(r++ < l) str += ')';
                res.push_back(str);
            } else {
                st.push(str+"(");
                if(l > r) st.push(str+")");
            }
        }
        return res;
    }
};


int main() {
    Solution s;
    vector<string> v = s.generateParenthesis(8);
    cout<<endl;
    return 0;
}