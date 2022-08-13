#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int leastInterval(vector<char> tasks, int n) {
        int freq[26];
        for(int i=0;i<26;i++) freq[i] = 0; 
        for(char task : tasks) ++freq[task-'A'];

        int time = 0;
        priority_queue<int> taskQue;
        for (int f : freq) if (f != 0) taskQue.push(f);
        queue<pair<int,int>> upcomingTask; // task & time
        while(!taskQue.empty() || !upcomingTask.empty()) {
            if (!upcomingTask.empty() && upcomingTask.front().second <= time) {
                taskQue.push(upcomingTask.front().first);
                upcomingTask.pop();
            }
            time +=1; // timer
            if(!taskQue.empty()) {
                int task = taskQue.top() - 1; taskQue.pop();
                if(task > 0) upcomingTask.push({task, time + n});
            }
        }
        return time;
    }
};

int main() {
    Solution s;
    cout<<s.leastInterval({'A','A','A','B','B','B'}, 2)<<endl;
    return 0;
}