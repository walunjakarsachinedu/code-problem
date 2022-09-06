#include<bits/stdc++.h>
#include "print.cpp"
using namespace std;

class Solution {
public:
    struct Edge {
        int end, cost;
        Edge(int end, int cost): end(end), cost(cost) {}
        bool operator<(const Edge &e) const { return cost > e.cost; } // reversing operator for min heap
    };

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> dist(n+1, INT_MAX); // shortest distance from node K
        priority_queue<Edge> que;
        vector<Edge> adjList[n+1];

        for(auto time : times) adjList[time[0]].push_back({time[1], time[2]});

        que.push({k, 0});
        while(!que.empty()) {
            Edge e = que.top(); que.pop();
            if(dist[e.end] <= e.cost) continue;
            dist[e.end] = e.cost;
            for(auto neighbour : adjList[e.end]) que.push({neighbour.end, neighbour.cost + e.cost});
        }

        int t = 0; // t == INT_MAX  indicate graph is not connected
        for(int i=1;i<dist.size();i++) if(dist[i] > t) t = dist[i];
        return t == INT_MAX ? -1 : t;
    }
};


int main() {
    Solution s;
    //[[2,1,1],[2,3,1],[3,4,1]], n = 4, k = 2
    vector<vector<int>> times = {{2,1,1},{2,3,1},{3,4,1}};
    int m = s.networkDelayTime(times, 4, 2);
    cout<<m<<endl;
    return 0;
}