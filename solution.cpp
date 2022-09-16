#include<bits/stdc++.h>
#include "print.cpp"
using namespace std;

class Solution {
public:
    /**
     * @param words: a list of words
     * @return: a string which is correct order
     */
    string alienOrder(vector<string> &words) {
        map<char, vector<char>> graph;

        for(auto word : words) for(auto ch : word) graph[ch] = {};

        for(int i=0; i<words.size()-1; i++) {
            string w1 = words[i], w2 = words[i+1];
            int len = min(w1.size(), w2.size());
            if(w1.size() > w2.size() && w1.substr(0, len) == w2) return "";
            for(int j=0; j<len; j++) {
                char src = w1[j], dst = w2[j];
                if(src == dst) continue;
                graph[src].push_back(dst);
                break;
            }
        }
        
        priority_queue<char, vector<char>, greater<char>> que;
        map<char, int> indegree;
        for(auto node : graph) for(auto nei : node.second) ++indegree[nei];
        for(auto node : graph) if(!indegree[node.first]) que.push(node.first);
        string order = "";
        while(!que.empty()) {
            auto cur = que.top(); que.pop();
            order += cur;
            for(auto neighbour : graph[cur]) {
                --indegree[neighbour];
                if(!indegree[neighbour]) que.emplace(neighbour);
            }
        }
        return order.size() < graph.size() ? "" : order;
    }
};

int main() {
    Solution s;
    vector<string> words = {"zy", "zx"};
    string order = s.alienOrder(words);
    for(auto ch: order) cout<<ch<<" "; cout<<endl;
    return 0;
}
