#include<bits/stdc++.h>
#include "print.cpp"

// 36. Valid Sudoku
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
      set<char> setR, setC;
      map<int, set<char>> setB; // set for each box-id
      for(int j=0;j<9;j++) {
        for(int i=0;i<9;i++) {
          // check all row
          if(board[j][i] != '.') {
            if(setR.find(board[j][i]) != setR.end()) return false;
            setR.insert(board[j][i]);
          }
          // check all column
          if(board[i][j] != '.') {
            if(setC.find(board[i][j]) != setC.end()) return false;
            setC.insert(board[i][j]);
          }
          // check all box
          if(board[i][j] != '.') {
            int box_id = i/3 * 3 + j/3;
            if(setB[box_id].find(board[i][j]) != setB[box_id].end()) return false;
            setB[box_id].insert(board[i][j]);
          }
        }
        setR.clear();
        setC.clear();
      }

      return true;
    }
};

int main() {
  vector<vector<char>> sudoku = {
    {'5','3','.','.','7','.','.','.','.'},
    {'6','.','.','1','9','5','.','.','.'},
    {'.','9','.','.','.','.','.','6','.'},
    {'8','.','.','.','6','.','.','.','3'},
    {'4','.','.','8','.','3','.','.','1'},
    {'7','.','.','.','2','.','.','.','6'},
    {'.','6','.','.','.','.','2','8','.'},
    {'.','.','.','4','1','9','.','.','5'},
    {'.','.','.','.','8','.','.','7','9'}
  };
  bool isValid = Solution().isValidSudoku(sudoku);

  if(isValid) cout << "sudoku is valid" << endl;
  else cout << "sudoku is not valid" << endl;

  return 0;
}
