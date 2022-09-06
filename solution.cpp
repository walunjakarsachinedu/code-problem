#include<bits/stdc++.h>
#include "print.cpp"
using namespace std;

class Solution {
public:
    struct Node {
        int x, y, t;
        Node(int t, int x, int y): t(t), x(x), y(y) {}
        bool operator<(const Node& d) const { return t > d.t; } // reversing operator
    };

    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int result = max(grid[0][0], grid[n-1][n-1]);
        static int dirs[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        priority_queue<Node> que;
        que.push({grid[0][0], 0, 0}); // {grid[y][x], x, y} (represents node)
        while(!que.empty()) {
            Node node = que.top(); que.pop();
            result = max(result, node.t);
            for(auto &dir : dirs) { // exploration
                int dx = dir[0] + node.x, dy = dir[1] + node.y;
                if(dx < 0 || dx >= n || dy < 0 || dy >= n || grid[dy][dx] == -1) continue;
                if(dx == n-1 && dy == n-1) return result;
                que.push({grid[dy][dx], dx, dy});
            }
            grid[node.y][node.x] = -1;
        }
        return result;
    }
};


int main() {
    Solution s;
    vector<vector<int>> grid = {
        {10,12,4,6},
        {9,11,3,5},
        {1,7,13,8},
        {2,0,15,14}
    };
    int time = s.swimInWater(grid);
    cout<<"time: "<<time<<endl;
    return 0;
}

