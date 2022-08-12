#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        make_heap(stones.begin(), stones.end());
        while(!stones.empty()) {
            int a = stones.front();
            pop_heap(stones.begin(), stones.end()); stones.pop_back();
            if(stones.empty()) return a;
            int b = stones.front();
            pop_heap(stones.begin(), stones.end()); stones.pop_back();
            stones.push_back(abs(a-b));
            push_heap(stones.begin(), stones.end());
        }
        return stones.front();
    }
};

int main() {
    Solution s;
    vector<int> stones = {2,2};
    cout<<s.lastStoneWeight(stones);
    cout<<endl;
    return 0;
}