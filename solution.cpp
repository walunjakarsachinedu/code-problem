#include <bits/stdc++.h>
#include "print.cpp"
using namespace std;

// 70. Climbing Stairs
class Solution {
public:
    int climbStairs(int n) {
      vector<int> cache(n+2, -1);
      int one=1;
      int two=1;
      for(int i=1; i<n; i++) {
        int tmp = two;
        two = one + two;
        one = tmp;
      }
      return two;
    }    
};

int main() {
  cout << Solution().climbStairs(10) << endl;
  return 0;
}