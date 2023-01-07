#include <bits/stdc++.h>
#include "print.cpp"
using namespace std;


// 134. Gas Station
class Solution {
public:
  int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int N = cost.size();
    int totalCost = 0;
    for(int i=0; i<N; i++) gas[i] -= cost[i], totalCost += gas[i];
    return (totalCost < 0) ? -1 : maxSumCircularArray(gas).first;
  }
  
  /// @return range of circular subArray with maxSum
  pair<int,int> maxSumCircularArray(vector<int>& nums) {
    int l(-1), mr(0), ml(0);
    int m_size(0), c_size(0);
    for(int r=0; r<nums.size(); r++) {
      if(c_size <= 0) l = r;
      c_size = max(0, c_size) + nums[r];
      if(c_size > m_size) m_size = c_size, mr = r, ml = l;
    }
    for(int r=0; r<l && c_size>0; r++) {
      c_size += nums[r];
      if(c_size > m_size) m_size = c_size, mr = r, ml = l;
    }
    return {ml, mr};
  }
};

int main() {
  vector<int> gas = {2,3,4}, cost = {3,4,3};
  cout << Solution().canCompleteCircuit(gas, cost) << endl;
  return 0;
}