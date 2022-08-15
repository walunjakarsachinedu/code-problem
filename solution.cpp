#include<bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<int>> result;
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> permutation;
        _subsetsWithDup(nums, 0, permutation);
        return result;
    }

    void _subsetsWithDup(vector<int>& nums, int i, vector<int>& permutation) {
        result.push_back(permutation);
        set<int> visited;
        for(int j=i;j<nums.size();j++) {
            if(visited.find(nums[j]) == visited.end()) {
                visited.insert(nums[j]);
                permutation.push_back(nums[j]);
                _subsetsWithDup(nums, j+1, permutation);
                permutation.pop_back(); // backtracking
            }
        }
    }
};

int main() {
    Solution s;
    vector<int> nums = {1,1,2,2};
    s.subsetsWithDup(nums);
    return 0;
}

// [[], [1], [2], [1,1], [2,2], [1,2], [1,1,2], [1,2,2], [1,1,2,2]]