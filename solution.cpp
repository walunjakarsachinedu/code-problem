#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int> nums, int k) {
        k = nums.size() - k;
        return quickSelect(nums, 0, nums.size()-1, k);
    }
    
    int quickSelect(vector<int>& nums, int l, int r, int k) {
        int pivot = nums[r];
        int p = l;
        for(int i=l;i<=r;i++) {
            if(nums[i] < pivot) {
                swap(nums[i], nums[p]);
                ++p;
            }
        }
        swap(nums[r],nums[p]);
        if(k == p) return nums[k];
        if(k < p) return quickSelect(nums, l, p-1, k);
        else return quickSelect(nums, p+1, r, k);
    
        return 0;
    }
};

int main() {
    Solution s;
    cout<<s.findKthLargest({1,1}, 1)<<endl;
    return 0;
}