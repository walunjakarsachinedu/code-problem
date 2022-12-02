#include <bits/stdc++.h>
#include "print.cpp"
using namespace std;

// 1657. Determine if Two Strings Are Close

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        map<char,int> freq1, freq2;
        for(char ch : word1) ++freq1[ch];
        for(char ch : word2) ++freq2[ch];
        multiset<int> s1, s2;
        for(auto f : freq1) s1.insert(f.second);
        for(auto f : freq2) s2.insert(f.second);

        for(auto c1=freq1.begin(), c2=freq2.begin(); 
           c1!=freq1.end() && c2!=freq2.end(); ++c1, ++c2) {
            if(c1->first != c2->first) return false;
        }

        if(s1!=s2) return false;

        return true;
    }
};


int main() {
  cout << Solution().closeStrings("abc", "bca") << endl;
}