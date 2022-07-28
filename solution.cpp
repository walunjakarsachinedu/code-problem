#include<bits/stdc++.h>
#include<iostream>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> freq(26,0);
        for(int ch : s1) ++freq[ch-97];

        bool isInclusion;
        vector<int> temp = freq;
        int l=0;
        for(int r=0;r<s2.size();r++) {
            if(temp[s2[r]-97] == 0) {
               while(temp[s2[r]-97] == 0) ++temp[s2[l++]-97];
            }
            --temp[s2[r]-97];

            isInclusion = true;
            for(int f : temp) if(f!=0) {
                isInclusion = false;
                break;
            }
            
            if(isInclusion) return true;
        }
        return false;
    }
};



int main() {
    Solution s;
    bool ispermutation = s.checkInclusion("nitin", "nitikntiinc");
    cout<<(ispermutation ? "is permutation" : "is not permutation")<<endl;
    return 0;
}