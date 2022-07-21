#include<bits/stdc++.h>
#include<iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
      int l=0;
      int r=s.size()-1;
      transform(s.begin(), s.end(), s.begin(), ::tolower);
      while(l<r){
        bool l_isalpha = isalnum(s[l]);
        bool r_isalpha = isalnum(s[r]);
        if(l_isalpha && r_isalpha) {
          if(s[l] != s[r]) return false;
        } else {
          if(!l_isalpha) ++l;
          if(!r_isalpha) --r;
          continue;
        }
        ++l;
        --r;
      }
      return true;
    }
};


int main() {
    Solution s;
    cout<< (s.isPalindrome("A man, a plan, a canal: Panama") ? "string is palindrome" : "string is not palindrome")<<endl;
    return 0;
}