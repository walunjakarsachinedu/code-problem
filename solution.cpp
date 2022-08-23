#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> preMap[numCourses];
        for (auto pre : prerequisites)
            preMap[pre[1]].push_back(pre[0]);
        
        vector<int> dependency(numCourses, 0);
        for(auto pre : prerequisites)
            ++dependency[pre[0]];
        
        queue<int> que;
        for(int i=0;i<numCourses;i++) {
            if(!dependency[i]) que.push(i);
        }

        vector<int> result;  result.reserve(numCourses);
        while(!que.empty()) {
            int course = que.front(); que.pop();
            for(auto i : preMap[course]) {
                --dependency[i];
                if(!dependency[i]) que.push(i);
            }
            result.emplace_back(course);
        }

        if(numCourses != result.size()) return {};
        return result;
    }
    
};

int main() {
    int numCourses = 4;
    vector<vector<int>> prerequisites = {{0,1}, {0,2}, {1,3}, {2,3}};
    Solution s;
    vector<int>  a = s.findOrder(4,prerequisites);
    for(auto i : a) cout<<i<<" "; cout<<endl;
    return 0;
}



/*
    0   
  1   2
    3   4
    
    3   4
  1   2
    0

order : 3 1 2 0

adj : 0 : 1 2
1 : 3
2 : 3

reverse-adj : 3 : 1 2
1 : 0
2 : 0

visitedCount : 
0 : 2
1 : 1 
2 : 1
3 : 0
*/