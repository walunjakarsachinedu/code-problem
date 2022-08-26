#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, set<string>> adjList;
        for(auto ticket : tickets) adjList[ticket[0]].insert(ticket[1]);

        for(auto p : adjList) {
            cout<< p.first << ':';
            for(auto i : p.second) cout<<" " <<i; cout<<endl;
        } 
        cout<<endl;
        vector<string> path;
        dfs(adjList, "JFK", path);
        reverse(path.begin(), path.end());

        return path;
    }
private:
    void dfs(unordered_map<string, set<string>>& adjList,
        string airport, vector<string>& result) {
        
        while (!adjList[airport].empty()) {
            string next = *adjList[airport].begin();
            adjList[airport].erase(adjList[airport].begin());
            dfs(adjList, next, result);
        }
        
        result.push_back(airport);
    }
};

int main() {
    Solution s;
    vector<vector<string>> tickets = {{"JFK", "SFO"}, {"SFO", "JFK"}, {"JFK", "ATL"}};
    auto path = s.findItinerary(tickets);
    for(auto p : path) cout<<" "<<p; cout<<endl;
    return 0;
}