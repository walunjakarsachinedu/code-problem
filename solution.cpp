#include<bits/stdc++.h>
#include<iostream>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        map<char,int> freq,window;
        for(char i : t) ++freq[i];
        int l=0;
        int have = 0;
        int needed = freq.size();
        pair<int,int> res = {0, s.size()};
        for(int r=0;r<s.size();r++) {
            ++window[s[r]];
            if(window[s[r]]==freq[s[r]]) ++have;
            if(have >= needed) {
                while(freq[s[l]] == 0 || window[s[l]] > freq[s[l]]) --window[s[l++]];
                if(r-l < res.second-res.first) res = {l, r};
            }
        }
        for(char ch : t) if(window[ch] < freq[ch])
            return "";
        return s.substr(res.first, res.second-res.first+1);
    }
};



int main() {
    Solution s;
    string subStr = s.minWindow("A", "AA");
    cout<<'"'<<subStr<<'"'<<endl;
    return 0;
}