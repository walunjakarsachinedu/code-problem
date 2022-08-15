#include<bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<int>> result;
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> combination;
        _combintationSum2(candidates, 0, target, combination);
        return result;
    }

    void _combintationSum2(vector<int>& candidates, int i, int target, vector<int>& combination) {
        if(target == 0) result.push_back(combination);
        if(target <= 0) return ; // base condition
        if(i<candidates.size() && candidates[i] > target) return ;

        int prev = -1; 
        for(int j=i;j<candidates.size();j++) {
            if(candidates[j] == prev) continue; // eliminate dublicate
            combination.push_back(candidates[j]);
            _combintationSum2(candidates, j+1, target-candidates[j], combination);
            combination.pop_back(); // backtracking
            prev = candidates[j];
        }
    }
};

int main() {
    Solution s;
    vector<int> nums = {1,1,1,3,3,5};
    s.combinationSum2(nums, 8);
    return 0;
}
