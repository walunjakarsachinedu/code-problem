#include <bits/stdc++.h>
#include "print.cpp"
using namespace std;

// 1207. Unique Number of Occurrences
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int,int> freq;
        for(int i: arr) ++freq[i];
        set<int> occurCount;
        for(auto i : freq) {
            if(occurCount.find(i.second) != occurCount.end())
                return false;
            occurCount.insert(i.second);
        }
        return true;
    }
};

int main() {
  vector<int> array = {1,2,2,1,1,3};
  bool hasUniqueOccurence = Solution().uniqueOccurrences(array);
  if(hasUniqueOccurence) cout << "unique occurences is present" << endl;
  else cout << "unique occurences is present" << endl;
  return 0;
}