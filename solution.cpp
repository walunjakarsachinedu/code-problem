#include <bits/stdc++.h>
#include "print.cpp"
using namespace std;

// 232. Implement Queue using Stacks
class MyQueue {
public:
  stack<int> in, out;

  void push(int x) {
    in.push(x);
  }
  
  int pop() {
    int top = peek(); out.pop();
    return top;
  }
  
  int peek() {
    if(out.empty()) while(!in.empty()) out.push(in.top()), in.pop();
    int top = out.top();
    return top;
  }
  
  bool empty() {
    return in.empty() && out.empty();
  }
};

int main() {
  MyQueue que;
  que.push(1);
  que.push(2);
  cout << "top element in queue: " << que.peek() << endl;
  cout << "poped element: " << que.pop() << endl;
  cout << "is queue empty : " << (que.empty() ? "true" : "false") << endl;
  return 0;
}