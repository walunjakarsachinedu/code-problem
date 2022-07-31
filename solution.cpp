#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int> temperatures) {
        stack<int> st;
        vector<int> res(temperatures.size());
        for(int i=0;i<temperatures.size();i++) {
            while(!st.empty() && temperatures[st.top()]<temperatures[i]) {
                res[st.top()] = i-st.top();
                st.pop();
            }
            st.push(i);
        }
        return res;
    }
};


int main() {
    Solution s;
    vector<int> v = s.dailyTemperatures({30,60,90});
    for(int i: v) cout<<i<<" ";
    cout<<endl;
    return 0;
}