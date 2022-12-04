#include <bits/stdc++.h>
#include "print.cpp"
using namespace std;

// 125. Valid Palindrome
class Solution {
public:
    bool isPalindrome(string s) {
        int l=0, r=s.size()-1;
        while(l<r) {
          if(!isAlpha(s[l])) ++l;
          else if(!isAlpha(s[r])) --r;
          else if(toSmall(s[l])!=toSmall(s[r])) 
            return false;
          else ++l, --r;
        }
        return true;
    }

    bool isAlpha(char c) {
      return (c>='a' && c <='z') || (c>='A' && c<='Z') || (c>='0' && c<='9');
    }
    char toSmall(char c) {
      return (c>='A' && c<='Z') ? c + 32 : c;
    }
};

int main() {
  
  return 0;
}