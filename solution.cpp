#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0;i<board.size();i++) 
            for(int j=0;j<board[0].size();j++) 
                if(_exist(board, i, j, word, 0)) return true;
        return false;
    }

    bool _exist(vector<vector<char>>& board, int i, int j, string word, int wIdx) {
        if(i<0 || j<0 || i>=board.size() || j>=board[0].size() || board[i][j] != word[wIdx]) return false;
        if(wIdx == word.size()-1) return true;

        board[i][j] = '*';
        bool res = _exist(board, i+1, j, word, wIdx + 1)
                || _exist(board, i-1, j, word, wIdx + 1)
                || _exist(board, i, j+1, word, wIdx + 1)
                || _exist(board, i, j-1, word, wIdx + 1);
        board[i][j] = word[wIdx];

        return res;
    }
};

int main() {
    Solution s;
    vector<vector<char>> board = {
        {'A', 'B', 'C', 'E'}, 
        {'S', 'F', 'C', 'S'}, 
        {'A', 'D', 'E', 'E'}};
    cout<<s.exist(board, "ABC")<<endl;
    return 0;
}
