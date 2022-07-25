#include<bits/stdc++.h>
#include<iostream>
using namespace std;

class Solution {
public:
    int maxArea(vector<int> height) {
        int res = 0;
        int begin = 0, end = height.size()-1;
        while(begin < end) {
            int area = (end-begin) * min(height[end],height[begin]);
            if(area > res) res = area;
            if(height[begin] < height[end]) ++begin;
            else --end;
        }
        return res;
    }
};


int main() {
    Solution s;
    int area = s.maxArea({1,8,6,2,5,4,8,3,7});
    cout<<"max area : "<<area<<endl;
    return 0;
}