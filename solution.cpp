#include<bits/stdc++.h>
using namespace std;

/*
INF -> room
0 -> gate
-1 -> wall
*/

#define INF INT_MAX

struct pos {
    int x;
    int y;
    pos(int x=0, int y=0): x(x), y(y) {}
};

class Solution {
    int m, n;  // m -> height, n -> width   (of matrix)
public: 
    vector<vector<int>> wallsAndGates(vector<vector<int>>& rooms) {
        m = rooms.size(), n = rooms[0].size();
        queue<pos> que;
        for(int y=0; y<m; y++) for(int x=0; x<n; x++) if(rooms[y][x] == 0) que.push({x,y}); // store all gates position
        dfs(rooms,que);
        return rooms;
    }

    void dfs(vector<vector<int>>& rooms, queue<pos> que) {
        int distance = 1;
        vector<pos> direction = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        while(!que.empty()) {
            int len = que.size();
            for(int i=0;i<len;i++) {
                int r = que.front().y, c = que.front().x; que.pop();
                for(auto d : direction) {
                    int x = c + d.x, y = r + d.y;
                    if(x<0 || y<0 || x>=n || y>=m || rooms[y][x]!=INF) continue;
                    rooms[y][x] = distance;
                    que.push({x,y});
                }
            }
            ++distance;
        }
    }
};


void printRooms(vector<vector<int>>& rooms) {
    for(auto i : rooms) {
        for (auto j : i) {
            if(j>-1) cout<<" ";
            if (j == INF) cout << "I ";
            else cout << j << " ";
        }
        cout<<endl;
    }
}

int main() {
    Solution s;
    vector<vector<int>> rooms = {
        {INF, -1,    0, INF},
        {INF, INF, INF,  -1},
        {INF, -1,  INF,  -1},
        {0,   -1,  INF, INF},
    };
    s.wallsAndGates(rooms);
    printRooms(rooms);
    return 0;
}

