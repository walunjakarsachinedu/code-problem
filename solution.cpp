#include<bits/stdc++.h>
#include<iostream>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=0;
        int maxlen = 0;
        vector<int> freq(26,0);
        for(int r=0;r<s.size();r++) {
            freq[s[r]-65]++;
            int maxfreq = *max_element(freq.begin(),freq.end());
            while((r-l+1)-maxfreq > k) {
                --freq[s[l]-65];
                ++l;
            }
            maxlen = max(maxlen,r-l+1);
        }
        return maxlen;
    }
};



int main() {
    Solution s;
    string str = "AABABBA";
    int length = s.characterReplacement(str,1);
    cout<<"length : "<<length<<endl;
    return 0;
}