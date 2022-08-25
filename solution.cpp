#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        map<string, vector<string>> adjList;
        for(auto word : wordList) {
            string current_word = word;
            for(int i=0;i<word.size();i++) {
                word[i] = '*';
                adjList[word].push_back(current_word);
                word = current_word;
            }
        }
        
        string tmp = endWord;
        tmp[0] = '*';
        if(!adjList[tmp].size()) return 0;
        
        int pathLen=0;
        queue<string> que; // stores words
        
        que.push(beginWord);
        while(!que.empty()) {
            int levels = que.size();
            ++pathLen;
            for(int l=0;l<levels;l++) {
                string word = que.front(); que.pop();
                if(word == endWord) return pathLen;
                // visit all pattern
                tmp = word;
                for(int i=0;i<word.size();i++) {
                    word[i] = '*';
                    if(!adjList[word].empty()) {
                        for(auto neighbour : adjList[word]) {
                            que.push(neighbour);
                        }
                        adjList[word].clear();
                    }
                    word = tmp;
                }
            }
        }
        return 0;
    }
};

int main() {
    Solution s;
    vector<string> wordList = {"hot","dot","dog","lot","log","cog"};
    int ladderLength = s.ladderLength("hit", "cog", wordList);
    cout<<"length of ladder is "<<ladderLength<<endl;
    return 0;
}