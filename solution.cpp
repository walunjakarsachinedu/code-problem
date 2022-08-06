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
    bool hasCycle(ListNode *head) {
        ListNode *slow=head, *fast=head;

        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;

            if(slow==fast) return true;
        }
        return false;
    }
};

int main() {
    Solution s;
    ListNode *head = new ListNode({1,2,3,4,5});
    head->get(5)->next = head->get(3);

    bool containsCycle = s.hasCycle(head);
    if(containsCycle) cout<<"linked-list has cycle"<<endl;
    else cout<<"linked-list has not cycle"<<endl;
    return 0;
}

