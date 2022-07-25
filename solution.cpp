#include<bits/stdc++.h>
#include<iostream>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int> nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        int size = nums.size();
        for(int i=0;i<size-1;i++) {
            int target = -nums[i];
            int begin = i+1;
            int end = size-1;

            while(begin < end) {
                int sum = nums[begin] + nums[end];
                if(sum < target) ++begin; 
                else if(sum > target) --end;
                
                else {
                    vector<int> entry = {nums[i], nums[begin], nums[end]};
                    res.push_back(entry);
                    while(begin < end && entry[1] == nums[begin]) ++begin;
                    while(begin < end && entry[2] == nums[end]) --end;
                }
            }
            while(i + 1 < size && nums[i] == nums[i+1]) ++i;
        }
        return res;
    }
};


int main() {
    Solution s;
    auto v = s.threeSum({-1,0,1,2,-1,-4});
    return 0;
}