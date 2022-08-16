#include<bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<string>> result;
public:
    vector<vector<string>> partition(string s) {
        vector<string> partition;
        _partition(s, 0, partition);
        return result;
    }

    void _partition(string& s, int idx, vector<string>& partition) {
        if(idx == s.size()) {
            for (string part : partition) { 
                int l = 0, r = part.size()-1;
                while (l < r) if(part[l++]!=part[r--]) return;
            }
            result.push_back(partition);
            return;
        }
        // adding element
        partition.push_back(string(1,s[idx]));
        _partition(s, idx+1, partition);
        partition.pop_back(); // backtracking

        // concatenate element
        if(partition.empty()) return;
        partition.back() += s[idx];
        _partition(s, idx+1, partition);
    }
};

int main() {
    Solution s;
    s.partition("nitin");
    return 0;
}
