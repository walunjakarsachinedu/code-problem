#include<bits/stdc++.h>
using namespace std;

/*
1,2,3
        
    {1}     {}

*/
class Solution {
    vector<vector<int>> result;
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        _subsets(nums, 0, {});
        return result;
    }
    void _subsets(vector<int>& nums, int i, vector<int> collection) {
        result.push_back(collection);
        for(int j=i;j<nums.size();j++) {
            vector<int> new_collection(collection);
            new_collection.push_back(nums[j]);
            _subsets(nums, j+1, new_collection);
        }
    }
};

int main() {
    Solution s;
    vector<int> nums = {};
    s.subsets(nums);

    return 0;
}