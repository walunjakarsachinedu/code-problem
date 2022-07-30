#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>nums, int k) {
        vector<int> res;
        deque<int> que;
        for(int l=0,r=0;r<nums.size();) {
            while(r-l+1 <= k) {
                while(!que.empty() && nums[que.back()] < nums[r]) 
                    que.pop_back();
                que.push_back(r);
                ++r;
            }
            while(!que.empty() && que.front() < l) que.pop_front();
            res.push_back(nums[que.front()]);
            ++l;
        }
        return res;
    }
};



int main() {
    Solution s;
    vector<int> result = s.maxSlidingWindow({1,-1},1);
    for(int n : result) cout<<n<<" ";
    cout<<endl;
    return 0;
}