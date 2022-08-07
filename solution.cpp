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
     }
 };

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*> lists) {
        int l = 0, r = lists.size()-1;
        while(r>0) {
            while(l<r) {
                lists[l] = mergeTwoList(lists[l], lists[r]);
                l++, r--;
            }
            l=0;
        }
        return lists[0];
    }

    ListNode* mergeTwoList(ListNode* list1, ListNode* list2) {
        ListNode* mergeList = new ListNode();
        ListNode* tail = mergeList;
        while(list1!= nullptr && list2 != nullptr) {
            if(list1->val < list2->val) {
                tail->next = list1;
                list1 = list1->next;
            }
            else {
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next;
        }
        tail->next = (list1) ? list1 : list2;

        return mergeList->next;
    }
};


int main() {
    Solution s;
    s.mergeKLists({new ListNode({1,5,10}),new ListNode({1,2,3}), new ListNode({0,2,3,4})})->print();
    return 0;
}