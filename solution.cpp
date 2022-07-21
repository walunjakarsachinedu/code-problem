#include<bits/stdc++.h>
#include<iostream>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int> nums) {
        if(nums.size()==0) return 0;
        sort(nums.begin(),nums.end());
        int sequence_size = 1;
        int max = 0;
        int previous = nums[0];
        for(int num : nums) {
            if(num-previous == 1) ++sequence_size;
            else if(num == previous) continue;
            else {
                if(sequence_size > max)
                    max = sequence_size;
                sequence_size = 1;
            }
            previous = num;
        }
        if(sequence_size > max)
            max = sequence_size;
        return max;
    }
};


int main() {
    Solution s;
    int size = s.longestConsecutive({0,1,1,2,3});
    cout<<size<<endl;
    return 0;
}