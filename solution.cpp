#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        set<char> left_bracket = {'(','{','['};
        unordered_map<char,char> matching_bracket = {{'(',')'},{'{','}'},{'[',']'}};
        for(char br : s) {
            if(left_bracket.find(br) != left_bracket.end())
                st.push(br);
            else {
                if(!st.empty() && matching_bracket[st.top()] == br) st.pop();
                else return false;
            }
        }
        if(!st.empty()) return false;
        return true;
    }
};


int main() {
    Solution s;
    bool b = s.isValid("]");
    cout<< (b ? "true" : "false") << endl;
    return 0;
}