#include<bits/stdc++.h>
using namespace std;

struct Node {
    Node* children[26];
    bool isEnd;
    Node(char val=' ') : isEnd(false) {
        for(int i=0;i<26;i++) children[i] = nullptr;
    }

};

class Tries {
public:
    Node* head = new Node();
    Tries() {}
    Tries(vector<string>& words) {
        for(string word : words) addWord(word);
    }

    void addWord(string word) {
        Node* node = head;
        for(int i=0;i<word.size();i++) {
            if(node->children[word[i]-97]==nullptr) node->children[word[i]-97] = new Node(word[i]);
            node = node->children[word[i]-97];
        }
        node->isEnd = true;
    }

    bool search(string word) {
        Node* node = head;
        for(int i=0;i<word.size();i++) {
            if(node->children[word[i]-97] == nullptr) return false;
            node = node->children[word[i]-97];
        }
        return node->isEnd;
    }
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Tries trie(words);
        for(int i=0;i<board.size();i++) {
            for(int j=0;j<board[0].size();j++) {
                if(i==1 && j==3) {
                    int a= 3;
                }
                _findWords(board, trie.head, j, i, "");
                if(result.size() == words.size()) return words;
            }
        }
        return vector<string>(result.begin(), result.end());
    }

private:
    set<string> result;
    void _findWords(vector<vector<char>>& board, Node* node, int x, int y, string matched_word) {
        if(y<0 || x<0 || x==board[0].size() || y==board.size() || board[y][x]==' ') return;
        char ch = board[y][x];

        if(node->children[ch-97] == nullptr) return;

        node = node->children[ch-97];
        matched_word += ch;
        board[y][x]=' ';
        if(node->isEnd) result.insert(matched_word);

        _findWords(board, node, x-1, y, matched_word);
        _findWords(board, node, x+1, y, matched_word);
        _findWords(board, node, x, y-1, matched_word);
        _findWords(board, node, x, y+1, matched_word);
        board[y][x]=ch;
    }
};

int main() {
    Solution s;
    vector<vector<char>> board = {{'a', 'b'}};
    vector<string> words = {"ba"};
    vector<string> word_found = s.findWords(board, words);
    for(string word : word_found) cout<<word<<" ";
    cout<<endl;
    return 0;
}

 
 