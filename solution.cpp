#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> numToStr = {
        "","",  "abc", "def", 
        "ghi",  "jkl", "mno", 
        "pqrs", "tuv", "wxyz"
    };

    vector<string> letterCombinations(string digits) {
        vector<string> allCombinations = {""};
        for(auto digit : digits) {
            string letters = numToStr[stoi(string(1,digit))];
            allCombinations = combination(allCombinations, letters);
        }
        if(digits.empty()) return {};
        return allCombinations;
    }

    vector<string> combination(vector<string> s1, string s2) {
        vector<string> result;
        for(auto ch1 : s1) {
            for(auto ch2 : s2) result.push_back(ch1+ch2);
        }
        return result;
    }
};

int main() {
    Solution s;
    auto a = s.letterCombinations("23");
    for(auto i : a) cout<<i<<" "; cout<<endl;
    return 0;
}
