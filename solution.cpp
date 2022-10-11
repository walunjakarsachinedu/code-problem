#include<bits/stdc++.h>
#include "print.cpp"
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        int one = 1;
        int two = 1;
        for(int i=1;i<n;i++) {
            int tmp = two;
            two = one + two;
            one = tmp;
        }
        return two;
    }
};


int main() {
    Solution s;
    cout<<s.climbStairs(4)<<endl;
    return 0;
}
