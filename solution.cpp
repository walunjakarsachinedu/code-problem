#include<bits/stdc++.h>
#include "print.cpp"
using namespace std;


// 3. Longest Substring Without Repeating Characters
class Solution {
public:
    // O(nlogn)
    int lengthOfLongestSubstring(string s) { 
      unordered_set<char> st;
      int l=0;
      int maxLen = 0;
      for(int r=0; r<s.size(); ++r) {
        while(st.find(s[r]) != st.end()) st.erase(s[l++]);
        st.insert(s[r]);
        maxLen = max(maxLen, r-l+1);
      }
      return maxLen;
    }

    // optimize solution : O(n)
    int _lengthOfLongestSubstring(string s) {
        // sym : last pos + 1
        unordered_map<char, int> map;
        int left = 0;
        int maxLen = 0;

        for (int i = 0; i < s.size(); i++) {
            left = max(map[s[i]], left);
            maxLen = max(maxLen, i - left + 1);
            map[s[i]] = i + 1;
        }
        return maxLen;
    }


};


int main() {
  int len = Solution().lengthOfLongestSubstring("abcabcbb");
  cout << len << endl;
  return 0;
}

