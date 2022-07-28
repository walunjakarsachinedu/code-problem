#include<bits/stdc++.h>
#include<iostream>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l = 0;
        int r = 1;
        int max_profit = 0;
        while(r < prices.size()) {
            if(prices[r] > prices[l]) max_profit = max(prices[r] - prices[l],max_profit);
            else l = r;
            r++;
        }
        return max_profit;
    }
};



int main() {
    Solution s;
    vector<int> prices = {1,2,4,2,5,7,2,4,9,0,9};
    int total = s.maxProfit(prices);
    cout<<"profit : "<<total<<endl;
    return 0;
}