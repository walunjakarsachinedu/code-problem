#include<vector>
#include<iostream>
using namespace std;


class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n= cost.size();
        int one=0, two=0;
        for(int i=cost.size()-1;i>-1;i--) {
            int tmp = one;
            one = min(one, two) + cost[i];
            two = tmp;
        }
        return min(one,two);
    }
};

int main() {
    Solution s;
    vector<int> cost = {1,100,1,1,1,100,1,1,100,1};
    cout<<s.minCostClimbingStairs(cost)<<endl;
    return 0;
}