#include <bits/stdc++.h>
#include "print.cpp"
using namespace std;


// 520. Detect Capital
class Solution {
public:
    bool detectCapitalUse(string word) {
      if(isSmall(word[0])) {
        for(int i=1; i<word.size(); i++) {
          if(!isSmall(word[i])) return false;
        }
      }
      else {
        bool isCase = word.size() > 1 && isSmall(word[1]);
        for(int i=2; i<word.size(); i++)  {
          if(isCase != isSmall(word[i])) return false;
        }
      }
      return true;
    }

    bool isSmall(char ch) {
      return ch >= 'a' && ch <= 'z';
    }
};


int main() {
  string word = "USA";
  cout << Solution().detectCapitalUse(word) << endl;
  return 0;
}