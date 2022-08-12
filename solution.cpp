#include<bits/stdc++.h>
using namespace std;

class KthLargest {
public:
    vector<int> heap;
    int k;
    KthLargest(int k, vector<int> nums): k(k) {
        heap = vector<int>(nums.begin(), nums.end());
        make_heap(heap.begin(), heap.end(), greater<int>());
        while(heap.size() > k) {
            pop_heap(heap.begin(), heap.end(), greater<int>());
            heap.pop_back();
        }
    }
    
    int add(int val) {
        if(heap.size() >= k) {
            if(val > heap.front()) {
                pop_heap(heap.begin(), heap.end(), greater<int>());
                heap.pop_back();
            } 
            else return heap.front();
        }
        heap.push_back(val);
        push_heap(heap.begin(), heap.end(), greater<int>());
        return heap.front();
    }
};

int main() {
    KthLargest kthLargest(2, {0});
    cout<<kthLargest.add(-1)<<endl;
    cout<<kthLargest.add(1)<<endl;
    cout<<kthLargest.add(-2)<<endl;
    cout<<kthLargest.add(-4)<<endl;
    cout<<kthLargest.add(3)<<endl;
    return 0;
}