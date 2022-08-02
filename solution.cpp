#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int carFleet(int target, vector<int> position, vector<int> speed) {
        int size = position.size();
        vector<pair<int,int>> cars;
        for(int i=0;i<size;i++) cars.push_back({position[i],speed[i]});
        sort(cars.begin(),cars.end());

        stack<pair<int,int>> st;
        st.push(cars[size-1]);
        for(int i=size-2;i>=0;i--) {
            pair<int,int> c1 = st.top();
            pair<int,int> c2 = cars[i];
            double t1 = double (target - c1.first) / c1.second;
            double t2 = double (target - c2.first) / c2.second;
            if(t2 > t1) st.push(cars[i]);
        }
        return st.size();
    }
};

int main() {
    Solution s;
    int carfleet_count = s.carFleet(10,{6,8},{3,2});
    cout<<"no of car fleet: "<<carfleet_count<<endl;
    return 0;
}