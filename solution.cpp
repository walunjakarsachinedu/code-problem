#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int> nums, int target) {
        int l=0, r=nums.size()-1;
        while(l<=r) {
            int mid = (r-l)/2 + l;
            if(target == nums[mid]) return mid;
            //left sorted part
            else if(nums[l] <= nums[mid]) {
                //not in range
                if(target < nums[l] || target > nums[mid]) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            } 
            //right sorted part
            else {
                //not in range
                if(target < nums[mid] || target > nums[r]) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
        }
        return -1;
    }
};

int main() {
    Solution s;
    cout<<s.search({5,1,3}, 1)<<endl;
    return 0;
}