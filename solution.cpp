#include<bits/stdc++.h>
using namespace std;

/*
algorithm: 
    left part = max_heap
    right part = min_heap
    following should be always true:
        max_heap.values < min_heap.values
        max_heap.size <= min_heap.size + 1 
        min_heap.size <= max_heap.size + 1

array: 1 2 3 4
max_heap: 2 1 
min_heap: 3 4
*/

class MedianFinder {
    priority_queue<int, vector<int>, greater<int>> min_heap;
    priority_queue<int,vector<int>, less<int>> max_heap;
public:
    MedianFinder() {}

    void addNum(int num) {
        max_heap.push(num);
        if((!min_heap.empty() && max_heap.top() > min_heap.top()) || max_heap.size() > min_heap.size() + 1) {
            min_heap.push(max_heap.top());
            max_heap.pop();
        }
        if(max_heap.size() + 1 < min_heap.size()) {
            max_heap.push(min_heap.top());
            min_heap.pop();
        }
    }
    
    double findMedian() {
        if(min_heap.size() == max_heap.size()) return ((double) max_heap.top() + min_heap.top()) / 2;
        return (max_heap.size() > min_heap.size()) ? max_heap.top() : min_heap.top();
    }
    
    void print() {
        cout<<"max_heap: ";
        while (!max_heap.empty()) {
            cout << max_heap.top() << " ";
            max_heap.pop();
        }
        cout<<endl;

        cout<<"min_heap: ";
        while (!min_heap.empty()) {
            cout << min_heap.top() << " ";
            min_heap.pop();
        }
        cout<<endl;
    }
};



int main() {
    double median = 0;
    //[[],[1],[],[2],[],[3],[],[4],[],[5],[],[6],[],[7],[],[8],[],[9],[],[10],[]]
    MedianFinder medianFinder;
    medianFinder.addNum(1);    
    medianFinder.addNum(2); 
    medianFinder.addNum(3);    
    medianFinder.addNum(4);    
    medianFinder.addNum(5);    
    medianFinder.addNum(6); 
    medianFinder.addNum(7); 
    medianFinder.addNum(8); 
    medianFinder.addNum(9); 
    medianFinder.addNum(10); 
    cout<<medianFinder.findMedian()<<endl;
    return 0;
}