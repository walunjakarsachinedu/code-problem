#include<bits/stdc++.h>
using namespace std;

class Solution {
    int m, n; // m -> height, n -> width   (of matrix)
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        set<pair<int,int>> pacificOcean, atlanticOcean;
        m=heights.size(), n=heights[0].size();
        
        for(int x=0; x<n; x++) {
            dfs(heights, x, 0, pacificOcean, heights[0][x]);
            dfs(heights, x, m-1, atlanticOcean, heights[m-1][x]);
        }
        for(int y=0; y<m; y++) {
            dfs(heights, 0, y, pacificOcean, heights[y][0]);
            dfs(heights, n-1, y, atlanticOcean, heights[y][n-1]);
        }
        
        vector<vector<int>> result;
        for(auto i : pacificOcean) if(atlanticOcean.find(i) != atlanticOcean.end()) {
            result.push_back({i.second, i.first});
        }
        return result;
    }
    
    void dfs(vector<vector<int>>& heights, int x, int y, set<pair<int,int>>& visited, int prevHeight) {
        if(x<0 || y<0 || x>=n || y>=m || visited.find({x,y})!=visited.end() || heights[y][x] < prevHeight) return;
        
        visited.insert({x,y});
        prevHeight = heights[y][x];
        
        dfs(heights, x+1, y, visited, prevHeight);
        dfs(heights, x-1, y, visited, prevHeight);
        dfs(heights, x, y+1, visited, prevHeight);
        dfs(heights, x, y-1, visited, prevHeight);
    }
};

int main() {
    Solution s;
    vector<vector<int>> heights = {
        {1,2,2,3,5},
        {3,2,3,4,4},
        {2,4,5,3,1},
        {6,7,1,4,5},
        {5,1,1,2,4},
    };
    s.pacificAtlantic(heights);
    return 0;
}
