#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    /* 
        eliminate the sorted part 
        then you get unsorted part
        return minimum of unsorted part
    */
    int findMin(vector<int> nums) {
        int size = nums.size();
        int l=0, r=size-1;

        if(nums[l] <= nums[r]) return nums[l];

        while(l<r) {
            int mid = (r-l)/2 + l;
            if(nums[l] <= nums[mid]) {
                l = mid+1;
                if(l < size && nums[mid] > nums[l])
                    return nums[l];
            } 
            else {
                r = mid-1;
                if(r >= 0 && nums[r] > nums[mid])
                    return nums[mid];
            }
        }
        return -1;
    }
};

int main() {
    Solution s;
    int min_value = s.findMin({11,13,15,17});
    cout << "min_value : " << min_value << endl;
    return 0;
}