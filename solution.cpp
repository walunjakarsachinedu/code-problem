#include<bits/stdc++.h>
using namespace std;
/*
algorithm: each course should form uncycled graph with its prerequisite
important note: to make this algorithm to work, use backtracking 
*/
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        map<int, set<int>> preMap;
        for(auto pre : prerequisites) preMap[pre[0]].insert(pre[1]);
        vector<bool> visiting(numCourses, false);
        for(int course=0; course<numCourses; course++) {
            if(!dfs(course, preMap, visiting)) return false;
        }
        return true;
    }
    
    bool dfs(int course, map<int,set<int>>& preMap, vector<bool>& visiting) {
        if(visiting[course]) return false;
        if(preMap[course].empty()) return true;
        
        visiting[course] = true;
        auto prerequisites = preMap[course];
        for(auto pre : prerequisites)  
            if(!dfs(pre, preMap, visiting)) return false;
        visiting[course] = false;
        
        preMap[course].clear();
        
        return true;
    }
};


int main() {
    int numCourses = 4;
    vector<vector<int>> prerequisites = {{0,1}, {0,2}, {1,3}, {2,3}};
    Solution s;
    cout<<s.canFinish(numCourses, prerequisites);
    cout<<endl;
    return 0;
}

