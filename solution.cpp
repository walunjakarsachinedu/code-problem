#include<bits/stdc++.h>
using namespace std;

struct comparator{
    bool operator()(const vector<int>& a,const vector<int>& b) const{
        float distance_a = sqrt(a[0]*a[0] + a[1]*a[1]);
        float distance_b = sqrt(b[0]*b[0] + b[1]*b[1]);
        return distance_a < distance_b;
    }
};        
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>> points, int k) {
        make_heap(points.begin(),points.end(), comparator());
        while (points.size() != k) {
            pop_heap(points.begin(), points.end(), comparator());
            points.pop_back();
        }
        return points;
    }
};

int main() {
    Solution s;
    auto v = s.kClosest({{1,3},{-2,2}},1);
    for(auto i:v) {
        for(auto j:i) cout<<j<<" ";
        cout<<endl;
    }
    return 0;
}