#include<bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<int>> result;
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> permutation;
        _permute(nums, 0, permutation);
        return result;
    }

    void _permute(vector<int>& nums, int i, vector<int>& permutation) {
        if (permutation.size() == nums.size()) {
            result.push_back(permutation);
            return ;
        }
        for(int j=i;j<nums.size();j++) {
            swap(nums[j],nums[i]); permutation.push_back(nums[i]);
            _permute(nums, i+1, permutation);
            swap(nums[j],nums[i]);  permutation.pop_back(); // backtracking
        }
    }
};

int main() {
    Solution s;
    vector<int> nums = {1,2,3};
    s.permute(nums);
    return 0;
}