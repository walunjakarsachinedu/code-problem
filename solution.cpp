#include<bits/stdc++.h>
using namespace std;

class Solution {
    int max_area = 0;
    int m, n; // m -> height, n -> width  (of matrix)
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        for(int y=0; y<m; y++) {
            for(int x=0; x<n; x++) {
                int area=0;
                dfs(grid, x, y, area);
                max_area = max(area, max_area);
            }
        }
        return max_area;
    }
    
    void dfs(vector<vector<int>>& grid, int x, int y, int& area) {
        if(x<0 || y<0 || x>=n || y>=m || grid[y][x] == 0) return;
        
        ++area;
        grid[y][x] = 0;
        
        dfs(grid, x+1, y, area);
        dfs(grid, x-1, y, area);
        dfs(grid, x, y+1, area);
        dfs(grid, x, y-1, area);
    }
};

int main() {
    Solution s;
    vector<vector<int>> grid = {
        {0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0}, 
        {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0}, 
        {0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0}, 
        {0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0}, 
        {0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0}, 
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0}, 
        {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0}, 
        {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0}
        };
    int max_area = s.maxAreaOfIsland(grid);
    cout<<max_area<<endl;
    return 0;
}
