#include<bits/stdc++.h>
#include<iostream>
using namespace std;

class Solution {
public:
    int bruteForce(string s) {
        // brute force
        int maxlen = 0;
        int size = s.size();
        for(int i=0;i<size;i++) {
            set<char> character;
            for(int j=i;j<size;j++) {
                if(character.find(s[j]) != character.end()) break;
                character.insert(s[j]);
            }
            maxlen = max((int) character.size(),maxlen);
        }
        return maxlen;
    }

    int lengthOfLongestSubstring(string s) {
        int l = 0;
        int maxlen = 0;
        set<char> characters;
        for(int r=0; r<s.size(); r++) {
            while(characters.find(s[r]) != characters.end()) 
                characters.erase(characters.find(s[l++]));
            characters.insert(s[r]);
            maxlen = max(maxlen, r-l+1);
        }

        return maxlen;
    }
};



int main() {
    Solution s;
    int length = s.lengthOfLongestSubstring("abacd");
    cout<<"length : "<<length<<endl;
    return 0;
}