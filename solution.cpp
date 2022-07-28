#include<bits/stdc++.h>
#include<iostream>
using namespace std;

class Solution {
public:
    // 0,1,0,2,1,0,1,3,2,1,2,1
    int trapWithoutTwoPointer(vector<int> height) {
        int size = height.size();
        if(size < 3)  return 0;
        
        int total_water = 0;
        vector<int> lMax,rMax;
        int lm = height[0], rm = height[size-1];
        for(int i=0;i<size;i++) {
            lm = max(lm, height[i]);
            rm = max(rm, height[size-1-i]);
            lMax.push_back(lm);
            rMax.push_back(rm);
        }
        for(int i=1;i<size-1;i++) {
            int water = min(lMax[i-1],rMax[size-1-i]) - height[i];
            total_water += max(water, 0);
        }
        return total_water;
    }

    int trap(vector<int> height) {
        int size = height.size();
        if(size < 3) return 0;
        int l = 0, ml = height[0];
        int r = size-1, mr = height[size-1];
        int water = 0;
        
        while(l <= r) { //2,0,2
            if(height[l] <= height[r]) {
                if(height[l] > ml) ml = height[l];
                else water += ml-height[l];
                l++;
            } else {
                if(height[r] > mr) mr = height[r];
                else water += mr-height[r];
                r--;
            }
        }
        return water;
    }
};



int main() {
    Solution s;
    int total = s.trap({4,2,0,3,2,5});
    cout<<"water : "<<total<<endl;
    return 0;
}