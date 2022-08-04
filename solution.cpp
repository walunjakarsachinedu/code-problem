#include<bits/stdc++.h>
using namespace std;

class TimeMap {
    unordered_map<string, vector<pair<string,int>>> timeMap;
public:
    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        timeMap[key].push_back({value, timestamp});
    }

    // uses binary search for getting value, so time complexity is O(logn)
    string get(string key, int timestamp) {
        auto& values = timeMap[key];
        int l=0,r=values.size()-1;
        string res;
        while(l<=r) {
            int m = (r-l)/2+l;
            if(timestamp >= values[m].second) {
                res = values[m].first;
                l=m+1;
            } else {
                r=m-1;
            }
        }
        return res;
    }
};


int main() {
    TimeMap timeMap;
    timeMap.set("foo", "bar", 1);  // store the key "foo" and value "bar" along with timestamp = 1.
    timeMap.get("foo", 1);         // return "bar"
    timeMap.get("foo", 3);         // return "bar", since there is no value corresponding to foo at timestamp 3 and timestamp 2, then the only value is at timestamp 1 is "bar".
    timeMap.set("foo", "bar2", 4); // store the key "foo" and value "bar2" along with timestamp = 4.
    timeMap.get("foo", 4);         // return "bar2"
    timeMap.get("foo", 5);         // return "bar2"
    return 0;
}