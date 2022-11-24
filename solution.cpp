#include<bits/stdc++.h>
#include "print.cpp"
using namespace std;

// 1926. Nearest Exit from Entrance in Maze
class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& e) {
      int R = maze.size();
      int C = maze[0].size();
      vector<pair<int,int>> direction =  {{1,0}, {0,1}, {-1,0}, {0,-1}};
      queue<pair<int,int>>  que;
      que.push({e[0], e[1]});
      maze[e[0]][e[1]] = '+'; // mark visited

      for(int r=0; r<R; r++) {
        if(maze[r][0] == '.') maze[r][0] = 'e';
        if(maze[r][C-1] == '.') maze[r][C-1] = 'e';
      }
      for(int c=0; c<C; c++) {
        if(maze[0][c] == '.') maze[0][c] = 'e';
        if(maze[R-1][c] == '.') maze[R-1][c] = 'e';
      }

      int step = 1;
      while(!que.empty()) {
        int levelSize = que.size();
        for(int i=0; i<levelSize; i++) {
          auto [r,c] = que.front(); que.pop();
          for(auto [dr, dc] : direction) {
            dr += r, dc += c;
            if(dr < 0 || dc < 0 || dr >= R || dc == C || maze[dr][dc] == '+') continue;
            que.push({dr, dc});
            //if(dr == 0 || dc == 0 || dr == R-1 || dc== C-1) 
            if(maze[dr][dc] == 'e') return step;
            maze[dr][dc] = '+'; // mark visited
          }
        }
        ++step;
      }
      return -1;
    }
};

int main() {
  vector<int> entrance = {1,0};
  vector<vector<char>> maze = {
    {'+','+','+','+'},
    {'.','.','+','+'},
    {'+','.','.','+'},
    {'+','+','.','+'}
  };
  Solution s;
  cout << s.nearestExit(maze, entrance) << endl;
  return 0;
}


