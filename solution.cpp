#include<bits/stdc++.h>
using namespace std;

class MinStack {
private: 
    vector<int> arr;
    int min_value = INT_MAX;
    
public:
    MinStack() {}
    
    void push(int val) {
        arr.push_back(val);
        min_value = min(min_value, val);
    }
    
    void pop() {
        if(arr.empty()) return;
        arr.erase(arr.end()-1);
        min_value = INT_MAX;
        for(int v : arr) min_value = min(min_value, v);
    }
    
    int top() {
        return arr.back();
    }
    
    int getMin() {
        return min_value;
    }
};


int main() {
    MinStack s;
    s.push(34);
    s.push(30);
    s.pop();
    return 0;
}