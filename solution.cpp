#include <bits/stdc++.h>
#include "print.cpp"
using namespace std;

// 11. Container With Most Water
class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxArea = 0;
        int l = 0;
        int r = height.size()-1;
        while(l < r) {
          int area = min(height[l], height[r]) * (r-l);
          maxArea = max(maxArea, area);
          (height[l] < height[r]) ?  ++l : --r;
        }
        return maxArea;
    }
};

int main() {
  vector<int> heights = {1,8,6,2,5,4,8,3,7};
  int maxWater = Solution().maxArea(heights);
  cout << "k: " << maxWater << endl;
  return 0;
}