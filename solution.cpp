#include<bits/stdc++.h>
#include "print.cpp"

// 79. Word Search
class Solution {
    vector<pair<int, int>> direction = {{1,0}, {0,1}, {-1,0}, {0,-1}};
public:
    bool exist(vector<vector<char>>& board, string word) {
      for(int r=0; r<board.size(); r++) {
        for(int c=0; c<board[0].size(); c++) {
          if (dfs(board, word, 0, r, c)) return true;
        }
      }
      return false;
    }

    bool dfs(vector<vector<char>>& board, string& word, int i, int r, int c) {
      if(board[r][c] != word[i]) return false;
      if(i == word.size()-1) return true;

      int tmp = board[r][c];
      board[r][c] = '.'; // marking visiting

      for(auto [dr, dc] : direction) {
        dr += r; dc += c;
        if(dr < 0 || dc < 0 || dr >= board.size() || dc >= board[0].size()) continue;
        if(dfs(board, word, i+1, dr, dc))
          return true;
      }

      board[r][c] = tmp; // marking visited
      return false;
    }
};

int main() {
  vector<vector<char>> board = {
    {'A','B','C','E'},
    {'S','F','C','S'},
    {'A','D','E','E'}
  };
  string word = "ABCCED";
  bool ispresent = Solution().exist(board, word);
  if(ispresent) cout << "word is present in board" << endl;
  return 0;
}
