#include<bits/stdc++.h>
#include "print.cpp"
using namespace std;

typedef pair<int,int> Point;
typedef pair<int, Point> Node;

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& pts) { // prim's algorithm for finding minimum spanning tree
        vector<Point> points;
        for(auto p : pts) points.push_back({p[0], p[1]});

        priority_queue<Node, vector<Node>, greater<Node>> frontier; // min heap
        frontier.push({0, points[0]});
        set<Point> visited;
        int cost = 0;

        while(!frontier.empty()) { 
            Node node = frontier.top(); frontier.pop();
            if(visited.find(node.second) != visited.end()) continue;
            visited.insert(node.second);
            cost += node.first;
            for(auto point : points) {
                if(visited.find(point) != visited.end()) continue;
                int distance = abs(node.second.first - point.first) + abs(node.second.second - point.second);
                frontier.push({distance, point});
            }
        }

        return cost;
    }
};

int main() {
    Solution s;
    vector<vector<int>> points = {{0,0},{2,2},{3,10},{5,2},{7,0}};
    int cost = s.minCostConnectPoints(points);
    cout<<"cost: "<<cost<<endl;
    return 0;
}