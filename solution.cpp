#include<bits/stdc++.h>
using namespace std;


class Solution {
    int count = 0;
public:
    int numIslands(vector<vector<char>>& grid) {
        for(int y=0; y<grid.size(); y++)
            for(int x=0; x<grid[0].size(); x++)
                if(grid[y][x] == '1') dfs(grid, x, y), ++count;
        return count;
    }
    
    void dfs(vector<vector<char>>& grid, int x, int y) {
        if(isLandVisited(grid, x, y)) return;
        
        grid[y][x] = '0';
        dfs(grid, x+1, y);
        dfs(grid, x-1, y);
        dfs(grid, x, y+1);
        dfs(grid, x, y-1);
    }
    
    bool isLandVisited(vector<vector<char>>& grid, int x, int y) {
        return (x<0 || y<0 || x>=grid[0].size() || y>=grid.size()) ||
            (grid[y][x] == '0');
    }
};


int main() {
    Solution s;
    vector<vector<char>> grid = {
        {'1', '1', '1', '1', '0'},
        {'1', '1', '0', '1', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '0', '0', '0'}};
    cout<<"number of islands are "<<s.numIslands(grid)<<endl;
    return 0;
}
