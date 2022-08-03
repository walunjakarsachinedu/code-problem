#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int> piles, int h) {
        int maxSpeed = *max_element(piles.begin(), piles.end());
        //k : 0 - maxSpeed
        int k=maxSpeed;
        int l=1, r=maxSpeed-1;
        while(l<=r) {
            int mid = (r-l)/2 + l;
            int total_hr = 0;
            for(int pile : piles) {
                total_hr += ceil(double(pile) / (mid));
            }
            if(total_hr <= h) {
                k = min(k, mid);
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return k;
    }
};


int main() {
    Solution s;
    int k = s.minEatingSpeed({1,1,1,999999999}, 10);
    cout<<"k: "<<k<<endl;
    return 0;
}