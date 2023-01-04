#include <bits/stdc++.h>
#include "print.cpp"
using namespace std;


// 2244. Minimum Rounds to Complete All Tasks
class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
      unordered_map<int, int> freq;
      for(int& task : tasks) ++freq[task];
      
      int rounds(0);
      for(auto [_, f] : freq) {
        if(f % 3 == 1 && f > 1) {
          ++rounds;
          f -= 2;
        }
        rounds += f / 3;
        int remainder(f % 3);
        if(remainder == 1) return -1;
        rounds += remainder / 2;
      }    
      return rounds;
    }
};

int main() {
  vector<int> tasks = {2,2,3,3,2,4,4,4,4,4};
  cout << Solution().minimumRounds(tasks) << endl;
  return 0;
}