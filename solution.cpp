#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestRectangleAreaMySolution(vector<int> heights) {
        stack<pair<int,int>> st; // pair<index, left-width>
        int largestArea = 0;
        for(int i=0;i<heights.size();i++) {
            int w=0;
            while(!st.empty() && heights[i] < heights[st.top().first]) {
                w += st.top().second + 1;
                int area = (i-st.top().first + st.top().second) * heights[st.top().first];
                largestArea = max(largestArea, area);
                st.pop();
            }
            st.push({i,w});
        }

        for(int i=1;!st.empty();i++) {
            int area = heights[st.top().first]*(i+st.top().second);
            largestArea = max(largestArea, area);
            i+=st.top().second;
            st.pop();
        }
        return largestArea;
    }
    int largestRectangleArea(vector<int> heights) {
        stack<pair<int,int>> st; //pair<index, height>
        int size = heights.size();
        int largest_area = 0;
        for(int i=0;i<size;i++) {
            int w = i;
            while(!st.empty() && st.top().second > heights[i]) {
                w = st.top().first;
                largest_area = max(largest_area, st.top().second * (i - st.top().first));
                st.pop();
            }
            st.push({w, heights[i]});
        }

        while(!st.empty()) {
            largest_area = max(largest_area, st.top().second * (size - st.top().first));
            st.pop();
        }
        return largest_area;
    }
};

int main() {
    Solution s;
    int area = s.largestRectangleArea({2,4});
    cout<<"largest area is "<< area <<endl;
    return 0;
}