#include <bits/stdc++.h>
#include "print.cpp"
using namespace std;


// 944. Delete Columns to Make Sorted
class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
      int N = strs.size();
      int M = strs[0].size();
      int count = 0;
      for(int c=0; c<M; c++) {
        for(int r=1; r<N; r++) {
          if(strs[r-1][c] > strs[r][c]) {
            count++; 
            break;
          }
        }
      }
      return count;
    }
};

int main() {
  vector<string> strs = {"zyx","wvu","tsr"};
  cout << Solution().minDeletionSize(strs) << endl;
  return 0;
}