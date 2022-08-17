#include<bits/stdc++.h>
using namespace std;


class Solution {
    vector<string> board; 
    vector<vector<string>> result;
public:
    vector<vector<string>> solveNQueens(int n) {
        for(int i=0;i<n;i++) board.push_back(string(n, '.'));
        _solveNQueens(0);
        return result;
    }

    void _solveNQueens(int y) {
        if(y==board.size()) {
            result.push_back(board);
            return;
        }
        for(int x=0;x<board.size();x++){
            if(isQueenUnderAttack(x, y)) continue;
            board[y][x] = 'Q';
            _solveNQueens(y+1);
            board[y][x] = '.'; // backtracking
        }
    }

    bool isQueenUnderAttack(int x, int y) {
        int m=x, n=y;
        while(isPositionValid(x, --y)) if(board[y][x] == 'Q') return true;
        x=m, y=n;
        while(isPositionValid(++x, --y)) if(board[y][x] == 'Q') return true;
        x=m, y=n;
        while(isPositionValid(--x, --y)) if(board[y][x] == 'Q') return true;
        return false;
    }

    bool isPositionValid(int x, int y) {
        return y >= 0 && x >= 0 && x < board.size();
    }

};


int main() {
    Solution s;
    auto a = s.solveNQueens(5);
    for (auto i : a) {
        for (auto j : i) {
            cout << j << " ";
            cout << endl;
        }
        cout<<endl;
    }
    cout<<"size of result is "<<a.size()<<endl;
    return 0;
}
