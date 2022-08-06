#include<bits/stdc++.h>
using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
     ListNode(vector<int> values) {
        vector<ListNode*> nodes(values.size());
        for(int i=0;i<values.size();i++) {
            nodes[i] = new ListNode(values[i]);
            if(i>0) nodes[i-1]->next = nodes[i];
        }
        val = nodes[0]->val;
        next = nodes[0]->next;
     }
     void print() {
        ListNode *node = this;
        while(node) cout<<node->val<<" ",node=node->next;
        cout<<endl;
     }

     ListNode* get(int value) {
        ListNode *node=this;
        while (node) {
            node = node->next;
            if (node->val == value) return node;
        }
        return nullptr;
     }
 };
 
class Solution {
public:
    // place all number to position equal to its value
    int findDuplicate(vector<int> nums) {
        for(int i=0;i<nums.size();i++) {
            int p = i;
            while(p != nums[p]) {
                if(nums[p] == nums[nums[p]]) return nums[p];
                swap(nums[p],nums[nums[p]]);
            }
        }
        return -1;
    }
    // distance from (start to start of loop) & (meeting of point of fast, slow pointer to start of loop)
    // is equal
    int findDuplicateFloydAlgorithm(vector<int> nums) {
        int slow=0, fast=0;
        while(true){
            slow = nums[slow];
            fast = nums[nums[fast]];
            if(slow==fast) break;
        }

        int slow2=0;
        while(true) {
            slow = nums[slow];
            slow2 = nums[slow2];
            if(slow==slow2) return slow;
        }
        return -1;
    }

};

int main() {
    Solution s;
    // 2 1 2
    int dublicate_number = s.findDuplicateFloydAlgorithm({3,1,3,4,2});
    cout<<dublicate_number<<endl;
    return 0;
}

