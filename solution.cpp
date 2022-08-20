#include<bits/stdc++.h>
using namespace std;

class Solution {
    int m, n; // m -> height, n -> width   (of board)
public:
    void solve(vector<vector<char>>& board) {
        m=board.size(), n=board[0].size();
        
        for(int x=0; x<n; x++) capture(board, x, 0, 'T'), capture(board, x, m-1, 'T');
        for(int y=0; y<m; y++) capture(board, 0, y, 'T'), capture(board, n-1, y, 'T');
        
        for(int y=0; y<m; y++) for(int x=0; x<n; x++) capture(board, x, y);        
        
        for(int y=0; y<m; y++) for(int x=0; x<n; x++) if(board[y][x]=='T') board[y][x] = 'O';        
    }
    
    void capture(vector<vector<char>>& board, int x, int y, char ch='X', char r_ch='O') { 
        if(x<0 || y<0 || x>=n || y>=m || board[y][x]!=r_ch) return;
        
        board[y][x] = ch;
        
        capture(board, x+1, y, ch, r_ch);
        capture(board, x-1, y, ch, r_ch);
        capture(board, x, y+1, ch, r_ch);
        capture(board, x, y-1, ch, r_ch);
    }
};



int main() {
    Solution s;
    vector<vector<char>> board = {{ 'X', 'X', 'X', 'X' }, { 'X', 'O', 'O', 'X' }, { 'X', 'X', 'O', 'X' }, { 'X', 'O', 'X', 'X' } };
    s.solve(board);
    cout<<"board: \n";
    for(auto i : board) {
        for(auto j : i) cout<<j<<" "; cout<<endl;
    }
    cout<<"\nboard after solving: \n";
    for(auto i : board) {
        for(auto j : i) cout<<j<<" "; cout<<endl;
    }

    return 0;
}
