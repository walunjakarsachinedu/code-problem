#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> result;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> combination;
        _combinationSum(candidates, 0, target, combination);
        return result;
    }

    void _combinationSum(vector<int>& candidates, int i, int target, vector<int>& combination) {
        if(target == 0) result.push_back(combination);
        if(target <= 0) return;

        combination.push_back(candidates[i]); // adding same element (repetition)
        _combinationSum(candidates, i, target-candidates[i], combination);
        combination.pop_back();

        for(int j=i+1;j<candidates.size();j++) {
            combination.push_back(candidates[j]); // adding new element
            _combinationSum(candidates, j, target-candidates[j], combination);
            combination.pop_back();
        }
    }
};

int main() {
    Solution s;
    vector<int> candidates = {2,3,5};
    s.combinationSum(candidates, 8);
    return 0;
}