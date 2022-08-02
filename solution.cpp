#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int> nums, int target) {
        int l = 0, r = nums.size()-1;
        while(l <= r) {
            int mid = r-l/2 + l;
            if(target == nums[mid]) return mid;
            else if(target < nums[mid]) {
                r = --mid;
            } else {
                l = ++mid;
            }
        }
        return -1;
    }
};

int main() {
    Solution s;
    int position = s.search({-1,0,3,5,9,12},2);
    cout<<"position: "<<position<<endl;
    return 0;
}