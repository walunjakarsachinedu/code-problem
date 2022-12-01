#include <bits/stdc++.h>
#include "print.cpp"
using namespace std;

// 1704. Determine if String Halves Are Alike
class Solution {
public:
    bool halvesAreAlike(string s) {
        string vowels = "aeiouAEIOU";

        int vowel1 = 0;
        for(int i=0;i<s.size()/2;i++) 
            if(vowels.find(s[i]) != SIZE_T_MAX) ++vowel1;
        
        int vowel2 = 0;
        for(int i=s.size()/2;i<s.size();i++) 
            if(vowels.find(s[i]) != SIZE_T_MAX) ++vowel2;

        return vowel1 == vowel2;
    }
};

int main() {
    if(Solution().halvesAreAlike("textbook")) cout << "halves are alike\n";
    else cout << "halves are not alike\n";

    return 0;
}