#include<bits/stdc++.h>
using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
     ListNode(vector<int> values) {
        vector<ListNode*> nodes;
        for(int i=0;i<values.size();i++) {
            nodes.push_back(new ListNode(values[i]));
            if(i>0) nodes[i-1]->next = nodes[i];
        }
        val = nodes[0]->val;
        next = nodes[0]->next;
     }

     void print() {
        ListNode* node = this;
        while(node) {
            cout<<node->val<<" ";
            node = node->next;
        }
        cout<<endl;
     }
 };

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* start = head;
        ListNode* end = head;
        ListNode* prev_end = nullptr;
        ListNode* res = nullptr;
        while(end) {
            for(int i=1;i<k;i++) {
                if(end) end = end->next;
                else break;
            }
            if(res==nullptr) res = end;
            if(end) {
                reverse(start,end); 
                swap(start, end); // swap for avoiding confusion
                if(prev_end) prev_end->next = start;
                prev_end = end; 
                start = end = end->next;
            }
        }
        if(res) return res;
        else return head;
    }

    ListNode* reverse(ListNode* start, ListNode* end) {
        ListNode* prev = end->next;//end->next;
        ListNode* next = nullptr;
        ListNode* head = end;
        ListNode* end_next = end->next;
        while(start != end_next) {
            next = start->next;
            start->next = prev;
            prev = start;
            start = next;
        }
        return head;
    }
};


int main() {
    Solution s;
    ListNode* node = new ListNode({1,2,3,4});
    s.reverseKGroup(new ListNode({1,2,3,4}),5)->print();
    //s.reverse(node,node->next->next->next)->print();
    
    return 0;
}